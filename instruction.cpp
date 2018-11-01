#include <cstdint> //using
#include <stdexcept> //std::exit

using word = uint32_t;

instruction::instruction(){
  opcode = 0;
  src_1 = 0;
  src_2 = 0;
  destn = 0;
  shift = 0;
  funct = 0;
  i_imi = 0;
  j_add = 0;
}

instruction::instruction(word inst){
  opcode = inst >> 26;
  if(is_R_type(opcode)){
    src_1 = (inst >> 21) & 0x1F;
    src_2 = (inst >> 16) & 0x1F;
    destn = (inst >> 11) & 0x1F;
    shift = (inst >> 6 ) & 0x1F;
    funct =  inst & 0x3F;
  }else if(is_I_type(opcode)){
    src_1 = (inst >> 21) & 0x1F;
    destn = (inst >> 16) & 0x1F;
    i_imi =  inst & 0xFFFF;
  }else if(is_J_type(opcode)){
    j_add =  inst & 0x3FFFFFF;
  }else{
    std::exit(-12); // opcodee not found, exit with error
  }
}

bool instruction::is_R_type(int opcode){
  return opcode = 0x00;
}
bool instruction::is_I_type(int opcode){
  return opcode == 0x04||opcode == 0x05||opcode == 0x06||opcode == 0x07||opcode == 0x08||
         opcode == 0x09||opcode == 0x0A||opcode == 0x0B||opcode == 0x0C||opcode == 0x0D||
         opcode == 0x0F||opcode == 0x23||opcode == 0x24||opcode == 0x25||opcode == 0x28||
         opcode == 0x29||opcode == 0x2B;
}
bool instruction::is_J_type(int opcode){
  return opcode == 0x02 || opcode == 0x03;
}
