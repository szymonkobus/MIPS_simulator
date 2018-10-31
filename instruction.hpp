#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <cstdint>    //using

using word_type = uint32;

class instruction{
public:
  int op_code;
  int src1, src2, dest;
  // R-type
  int shift;
  int funct;
  // I-type
  int imm;
  // J-type
  int j_address;

  instruction();
  instruction(word inst);
private:
  bool is_R_type(int opcod);
  bool is_I_type(int opcod);
  bool is_J_type(int opcod);
};

#endif
