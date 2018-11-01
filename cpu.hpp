#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include "memory.hpp"
#include "instruction.hpp"
#include "registers.hpp"

using word = uint32_t;

class cpu{
public: // change to private
  memory m;
  registers r;
  word pc;

public:
  cpu();
  cpu(std::string binary);
  void run();
private:
  //instructions
  void execute(const instruction& inst);
  void execute_r(const instruction& inst);
  void execute_i(const instruction& inst);
  void execute_j(const instruction& inst);

  void cpu::SLL(const instruction& inst);
  void cpu::SRL(const instruction& inst);
  void cpu::ADDU(const instruction& inst);
};

#endif
