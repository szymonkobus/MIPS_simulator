#include <string>
#include "cpu.hpp"
#include "instruction.hpp"

using word = uint32_t;
using signed_word = int32_t;

cpu::cpu(){
  pc = 0x10000000;
}

cpu::cpu(std::string binary): m(binary), r() {
  pc = 0x10000000;
}

void cpu::run(){
  while (true) {
    word next_instruction = m.read_inst(pc);
    instruction c_inst(next_instruction);
    this->execute(c_inst);
    pc += 4;
  }
}


void cpu::execute(const instruction& inst){
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
    case 0x21: ADDU(inst); break; //ADDU
    default: ;
  }
}


void cpu::execute_i(const instruction& inst){};
void cpu::execute_j(const instruction& inst){};

// INSTRUCTIONS
void cpu::SLL(const instruction& inst){
  signed_word data = r.get(inst.src_t) >> inst.shamt;
  r.set(inst.destn, data );
}

void cpu::SRL(const instruction& inst){
  signed_word data = r.get(inst.src_t) << inst.shamt;
  r.set(inst.destn, data);
}

void cpu::ADDU(const instruction& inst){
  word data = r.get(inst.src_s) + r.get(inst.src_t);
  r.set(inst.destn, data);
}

void cpu::ADD(const instruction& inst){}
void cpu::ADDI(const instruction& inst){ }
void cpu::ADDIU(const instruction& inst){ }
void cpu::ADDU(const instruction& inst){ }
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
void cpu::JR(const instruction& inst){ }
void cpu::LB(const instruction& inst){ }
void cpu::LBU(const instruction& inst){ }
void cpu::LH(const instruction& inst){ }
void cpu::LHU(const instruction& inst){ }
void cpu::LUI(const instruction& inst){ }
void cpu::LW(const instruction& inst){ }
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
void cpu::SLL(const instruction& inst){ }
void cpu::SLLV(const instruction& inst){ }
void cpu::SLT(const instruction& inst){ }
void cpu::SLTI(const instruction& inst){ }
void cpu::SLTIU(const instruction& inst){ }
void cpu::SLTU(const instruction& inst){ }
void cpu::SRA(const instruction& inst){ }
void cpu::SRAV(const instruction& inst){ }
void cpu::SRL(const instruction& inst){ }
void cpu::SRLV(const instruction& inst){ }
void cpu::SUB(const instruction& inst){ }
void cpu::SUBU(const instruction& inst){ }
void cpu::SW(const instruction& inst){ }
void cpu::XOR(const instruction& inst){ }
void cpu::XORI(const instruction& inst){ }
