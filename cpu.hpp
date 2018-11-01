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

  void cpu::ADD(const instruction& inst);
  void cpu::ADDI(const instruction& inst);
  void cpu::ADDIU(const instruction& inst);
  void cpu::ADDU(const instruction& inst);
  void cpu::AND(const instruction& inst);
  void cpu::ANDI(const instruction& inst);
  void cpu::BEQ(const instruction& inst);
  void cpu::BGEZ(const instruction& inst);
  void cpu::BGEZAL(const instruction& inst);
  void cpu::BGTZ(const instruction& inst);
  void cpu::BLEZ(const instruction& inst);
  void cpu::BLTZ(const instruction& inst);
  void cpu::BLTZAL(const instruction& inst);
  void cpu::BNE(const instruction& inst);
  void cpu::DIV(const instruction& inst);
  void cpu::DIVU(const instruction& inst);
  void cpu::J(const instruction& inst);
  void cpu::JALR(const instruction& inst);
  void cpu::JAL(const instruction& inst);
  void cpu::JR(const instruction& inst);
  void cpu::LB(const instruction& inst);
  void cpu::LBU(const instruction& inst);
  void cpu::LH(const instruction& inst);  
  void cpu::LHU(const instruction& inst);
  void cpu::LUI(const instruction& inst);
  void cpu::LW(const instruction& inst);
  void cpu::LWL(const instruction& inst);
  void cpu::LWR(const instruction& inst);
  void cpu::MFHI(const instruction& inst);
  void cpu::MFLO(const instruction& inst); 
  void cpu::MTHI(const instruction& inst); 
  void cpu::MTLO(const instruction& inst); 
  void cpu::MULT(const instruction& inst);
  void cpu::MULTU(const instruction& inst);
  void cpu::OR(const instruction& inst);
  void cpu::ORI(const instruction& inst);
  void cpu::SB(const instruction& inst);
  void cpu::SH(const instruction& inst);
  void cpu::SLL(const instruction& inst);
  void cpu::SLLV(const instruction& inst);
  void cpu::SLT(const instruction& inst);
  void cpu::SLTI(const instruction& inst);
  void cpu::SLTIU(const instruction& inst);
  void cpu::SLTU(const instruction& inst);
  void cpu::SRA(const instruction& inst);
  void cpu::SRAV(const instruction& inst);
  void cpu::SRL(const instruction& inst);
  void cpu::SRLV(const instruction& inst);
  void cpu::SUB(const instruction& inst);
  void cpu::SUBU(const instruction& inst);
  void cpu::SW(const instruction& inst);
  void cpu::XOR(const instruction& inst);
  void cpu::XORI(const instruction& inst);
};

#endif
