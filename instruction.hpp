#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <cstdint>    //using

using word_type = uint32;

class instruction{
public:
  int opcod;
  int src_1, src_2, destn;
  int shift;
  int funct;
  int i_imm;
  int j_add;

  instruction();
  instruction(word inst);
private:
  bool is_R_type(int opcod);
  bool is_I_type(int opcod);
  bool is_J_type(int opcod);
};

#endif
