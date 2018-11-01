#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include "memory.hpp"
#include "instruction.hpp"

using word = uint32_t;

class cpu{
private:
  //reg[0] == 0
  word reg[32];
  word pc;
public:
  cpu();
  void run(memory& m);
private:
  //instructions
  //void execute(instruction inst, memory& m);
  //void execute_r(instruction inst, memory& m);
  //void execute_i(instruction inst, memory& m);
  //void execute_j(instruction inst, memory& m);
};

#endif
