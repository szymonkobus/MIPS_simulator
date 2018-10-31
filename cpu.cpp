#include "cpu.hpp"

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
    this.execute(c_inst, m);
    pc += 4;
  }
}
