#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <cstdint>    //using

using word = uint32_t;

class instruction{
public:
  int opcode;
  int src_1, src_2, destn;
  int shift;
  int funct;
  int i_imm;
  int j_add;
  bool is_r;
  bool is_i;
  bool is_j;

  instruction();
  instruction(word inst);
private:
  bool is_R_type(int opcode);
  bool is_I_type(int opcode);
  bool is_J_type(int opcode);
};

#endif
