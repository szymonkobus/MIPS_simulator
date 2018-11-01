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
  void cpu::SRA(const instruction& inst);
  void cpu::JR(const instruction& inst);
  void cpu::MFHI(const instruction& inst);
  void cpu::MFLO(const instruction& inst);
  void cpu::MULT(const instruction& inst);
  void cpu::MULTU(const instruction& inst);
  void cpu::DIV(const instruction& inst);
  void cpu::DIVU(const instruction& inst);
  void cpu::ADD(const instruction& inst);
  void cpu::ADDU(const instruction& inst);
  void cpu::SUB(const instruction& inst);
  void cpu::SUBU(const instruction& inst);
  void cpu::AND(const instruction& inst);
  void cpu::OR(const instruction& inst);
  void cpu::XOR(const instruction& inst);
  void cpu::NOR(const instruction& inst);
  void cpu::NOR(const instruction& inst);
  void cpu::NOR(const instruction& inst);
  void cpu::NOR(const instruction& inst);
  void cpu::NOR(const instruction& inst);
  void cpu::NOR(const instruction& inst);
  void cpu::NOR(const instruction& inst);



};

#endif
