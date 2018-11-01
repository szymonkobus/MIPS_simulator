#include "cpu.hpp"
#include "instruction.hpp"

using word = uint32_t;

cpu::cpu(){
  pc = 0x10000000;
  for(int i = 0; i < 32; i++){
    reg[i] = 0;
  }
}

void cpu::run(memory& m){
  while (true) {
    word next_instruction = m.read_inst(pc);
    instruction c_inst(next_instruction);
    //this->execute(c_inst, m);
    pc += 4;
  }
}

/*
void cpu::execute(instruction inst, memory& m){
  switch(inst.type){
    case 'r': execute_r(inst, m); break;
    case 'i': execute_i(inst, m); break;
    case 'j': execute_j(inst, m); break;
    default: ;//TODO: Error
  }
}


void cpu::execute_r(instruction inst, memory& m){

  // PROBLEM: bad idea unless you understancd instructions very well
  // if we dont we have to check more things by hand (checking for exeptions and so on
  // just better to have scopes for everything)
  // doesn't work for register 0
  // make it bigger, speed doesnt matter
  //

  switch (inst.funct){
    case 0x00: reg[inst.destn] = reg[inst.src_2] << inst.shamt; break; //SLL
    case 0x02: reg[inst.destn] = reg[inst.src_2] >> inst.shamt; break; //SRL // IDK if it works
    //...
    case 0x21: reg[inst.destn] = reg[inst.src_1] + reg[inst.src_2]; break; //ADDU
    //...
  }
}
*/
