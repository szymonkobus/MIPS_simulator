#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include "memory.hpp"

using word = uint32_t;

class cpu{
private:
  //reg[0] == 0
  word reg[31];
  word pc;
public:
  cpu();
  void run(memory& m);
private:
  //instructions
  
};

#endif
