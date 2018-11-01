#include <string>
#include "cpu.hpp"
#include "instruction.hpp"

using word = uint32_t;

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
    case 0x00: SLL(inst); break; //SLL
    case 0x02: SRL(inst); break; //SRL
    case 0x21: ADDU(inst); break; //ADDU
    //....
    default: ;
  }
}


void cpu::execute_i(const instruction& inst){};
void cpu::execute_j(const instruction& inst){};

// INSTRUCTIONS
void cpu::SLL(const instruction& inst){
  r.set(inst.destn, (r.get(inst.src_t) >> inst.shamt) );
}

//void cpu::SRL
