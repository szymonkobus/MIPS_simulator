#include <string>
#include <iostream> //debug
#include <stdexcept> //std::exit

#include "cpu.hpp"
#include "instruction.hpp"

#include <iostream>

using word = uint32_t;
using signed_word = int32_t;

cpu::cpu(){
  pc = 0x10000000;
}

cpu::cpu(std::string binary): m(binary), r() {
  m.print_mem();
  pc = 0x10000000;
  npc = 0x10000004;
}

void cpu::run(){
  while(true) {
    std::cout << "run 1" << '\n';
    word next_instruction = m.read_inst(pc);

    std::cout << "run 2" << '\n';
    std::cout<<next_instruction<<std::endl; //debug
    instruction c_inst(next_instruction);

    std::cout << "run 3" << '\n';
    this->execute(c_inst);

    std::cout << "run 4" << '\n';
    //pc += 4;
    //this->reg_print(); //debug
    this->reg_s();
    if(npc == 0){
      std::cout<<"finshed execution!"<<std::endl;
      return;
    }
  }
}

void cpu::pc_increase(word offset){
  pc = npc;
  npc += offset;
}



void cpu::execute(const instruction& inst){
  std::cout<<"entered execute"<<std::endl;//debug
  switch(inst.type){
    case 'r': execute_r(inst); break;
    case 'i': execute_i(inst); break;
    case 'j': execute_j(inst); break;
    default: ;//TODO: Error
  }
}


void cpu::execute_r(const instruction& inst){
  switch (inst.funct){
    case 0x00: SLL(inst); break;  //SLL
    case 0x02: SRL(inst); break;  //SRL
    case 0x03: SRA(inst); break; //SRA
    case 0x08: JR(inst); break; //JR
    case 0x10: MFHI(inst); break; //MFHI
    case 0x12: MFLO(inst); break; //MFLO
    case 0x18: MULT(inst); break;
    case 0x19: MULTU(inst); break;
    case 0x1A: DIV(inst); break;
    case 0x1B: DIVU(inst); break;
    case 0x20: ADD(inst); break; //ADD
    case 0x21: ADDU(inst); break; //ADDU
    case 0x22: SUB(inst); break;
    case 0x23: SUBU(inst); break;
    case 0x24: AND(inst); break;
    case 0x25: OR(inst); break;
    case 0x26: XOR(inst); break;
    case 0x2A: SLT(inst); break;
    case 0x2B: SLTU(inst); break;

    default: ;
  }
}

void cpu::execute_i(const instruction& inst){
  switch (inst.opcode){
    case 0x20: ADDI(inst); break;
  }
};
void cpu::execute_j(const instruction& inst){};

// INSTRUCTIONS
void cpu::ADD(const instruction& inst){
  word r1 = r.get(inst.src_s); 
  word r2 = r.get(inst.src_t);
  signed_word res = r1 + r2;

  if((res <= 0 && r1 > 0 && r2 > 0)||(res >= 0 && r1 < 0 && r2 < 0)){
    std::cout<<"arithmetic error -10"<<std::endl;
    std::exit(-10);
  }
  r.set(inst.destn, res);
  pc_increase(4);
 }
void cpu::ADDI(const instruction& inst){
  word r1 = r.get(inst.src_s); 
  word r2 = r.get(inst.i_imi);
  signed_word res = r1 + r2;

  if((res <= 0 && r1 > 0 && r2 > 0)||(res >= 0 && r1 < 0 && r2 < 0)){
    std::cout<<"arithmetic error -10"<<std::endl;
    std::exit(-10);
  }
  r.set(inst.destn, res);
  pc_increase(4);
 }
void cpu::ADDIU(const instruction& inst){  
  word r1 = r.get(inst.src_s); 
  word r2 = r.get(inst.i_imi);
  signed_word res = r1 + r2;
  r.set(inst.destn, res);
 }
void cpu::ADDU(const instruction& inst){
  word res = r.get(inst.src_s) + r.get(inst.src_t);
  r.set(inst.destn, res);
  pc_increase(4);
 }
void cpu::AND(const instruction& inst){ }
void cpu::ANDI(const instruction& inst){ }
void cpu::BEQ(const instruction& inst){ }
void cpu::BGEZ(const instruction& inst){ }
void cpu::BGEZAL(const instruction& inst){ }
void cpu::BGTZ(const instruction& inst){ }
void cpu::BLEZ(const instruction& inst){ }
void cpu::BLTZ(const instruction& inst){ }
void cpu::BLTZAL(const instruction& inst){ }
void cpu::BNE(const instruction& inst){ }
void cpu::DIV(const instruction& inst){ }
void cpu::DIVU(const instruction& inst){ }
void cpu::J(const instruction& inst){ }
void cpu::JALR(const instruction& inst){ }
void cpu::JAL(const instruction& inst){ }
void cpu::JR(const instruction& inst){
  word jump_address = r.get(inst.src_s);
  pc = npc;
  npc = jump_address;
 }
void cpu::LB(const instruction& inst){ }
void cpu::LBU(const instruction& inst){ }
void cpu::LH(const instruction& inst){ }
void cpu::LHU(const instruction& inst){ }
void cpu::LUI(const instruction& inst){ }
void cpu::LW(const instruction& inst){

 }
void cpu::LWL(const instruction& inst){ }
void cpu::LWR(const instruction& inst){ }
void cpu::MFHI(const instruction& inst){ }
void cpu::MFLO(const instruction& inst){ }
void cpu::MTHI(const instruction& inst){ }
void cpu::MTLO(const instruction& inst){ }
void cpu::MULT(const instruction& inst){ }
void cpu::MULTU(const instruction& inst){ }
void cpu::OR(const instruction& inst){ }
void cpu::ORI(const instruction& inst){ }
void cpu::SB(const instruction& inst){ }
void cpu::SH(const instruction& inst){ }
void cpu::SLL(const instruction& inst){
  signed_word data = r.get(inst.src_t) >> inst.shamt;
  r.set(inst.destn, data);
  }
void cpu::SLLV(const instruction& inst){ }
void cpu::SLT(const instruction& inst){ }
void cpu::SLTI(const instruction& inst){ }
void cpu::SLTIU(const instruction& inst){ }
void cpu::SLTU(const instruction& inst){ }
void cpu::SRA(const instruction& inst){
  word data = r.get(inst.src_t) << inst.shamt;
  r.set(inst.destn, data);
 }
void cpu::SRAV(const instruction& inst){ }
void cpu::SRL(const instruction& inst){
  signed_word data = r.get(inst.src_t) << inst.shamt;
  r.set(inst.destn, data);
 }
void cpu::SRLV(const instruction& inst){ }
void cpu::SUB(const instruction& inst){ }
void cpu::SUBU(const instruction& inst){ }
void cpu::SW(const instruction& inst){ }
void cpu::XOR(const instruction& inst){ }
void cpu::XORI(const instruction& inst){ }


void cpu::test_fill(){
  r.set(8, (word)(0x7FFFFFFF));
  r.set(9, (word)0xFFFFFF);
  r.set(10, 2);
 }

void cpu::reg_print(){
  for(int i = 1; i < 32; i++){
    std::cout<<"reg"<<i<<"\t"<<r.get(i)<<std::endl;
  }
 }

void cpu::reg_s(){
  for(int i = 0; i < 4; i++){
      for(int j = 0; i < 8; j++)
      std::cout << r.get (i*8 + j) << "\t";
    std::cout << '\n';
  }
}
