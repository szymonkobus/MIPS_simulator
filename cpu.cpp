#include <string>
#include "cpu.hpp"
#include "instruction.hpp"

using word = uint32_t;

cpu::cpu(){
  pc = 0x10000000;
  for(int i = 0; i < 32; i++)
    reg[i] = 0;
}

cpu::cpu(std::string binary): m(binary) {
  pc = 0x10000000;
  for(int i = 0; i < 32; i++)
    reg[i] = 0;
}

void cpu::run(){
  while (true) {
    word next_instruction = m.read_inst(pc);
    instruction c_inst(next_instruction);
    this->execute(c_inst);
    pc += 4;
  }
}


void cpu::execute(instruction inst){
  switch(inst.type){
    case 'r': execute_r(inst); break;
    case 'i': execute_i(inst); break;
    case 'j': execute_j(inst); break;
    default: ;//TODO: Error
  }
}


void cpu::execute_r(instruction inst){
  switch (inst.funct){
    case 0x00: reg[inst.destn] = reg[inst.src_2] << inst.shamt; break; //SLL
    case 0x02: reg[inst.destn] = reg[inst.src_2] >> inst.shamt; break; //SRL
    case 0x21: reg[inst.destn] = reg[inst.src_1] + reg[inst.src_2]; break; //ADDU
  }
}


void cpu::execute_i(instruction inst){};
void cpu::  execute_j(instruction inst){};
