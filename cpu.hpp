#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include "memory.hpp"
#include "instruction.hpp"

using word = uint32_t;

class cpu{
private:
  //reg[0] == 0
  word reg[32] {0};
  word pc;
  memory m;
public:
  cpu();
  cpu(std::string binary);
  void run();
private:
  //instructions
  //void execute(instruction inst);
  //void execute_r(instruction inst);
  //void execute_i(instruction inst);
  //void execute_j(instruction inst);
};

#endif
