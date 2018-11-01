#include "cpu.hpp"
#include "instruction.hpp"

using word = uint32_t;

cpu::cpu(){
  pc = 0x10000000;
  for(int i = 0; i < 31; i++){
    reg[i] = 0;
  }
}

void cpu::run(memory& m){
  while (true) {
    word next_instruction = m.read_inst(pc);
    instruction c_inst(next_instruction);
    this->execute(c_inst, m);
    pc += 4;
  }
}

void cpu::execute(instruction inst, memory& m){
  if(inst.is_r){
    execute_r(inst, m);
  }
  else if(inst.is_i){
    execute_i(inst, m);
  }
  else if(inst.is_j){
    execute_j(inst, m);
  }
  else{
    //TODO throw errror invalid instruction
  }
}

void cpu::execute_r(instruction inst, memory& m){
  switch (inst.funct){
    case 0x00: reg[inst.destn] = reg[inst.src_2] << inst.shamt; break; //SLL
    case 0x02: reg[inst.destn] = reg[inst.src_2] >> inst.shamt; break; //SRL
    //...
    case 0x21: reg[inst.destn] = reg[inst.src_1] + reg[inst.src_2]; break; //ADDU
    //...
  }
}
