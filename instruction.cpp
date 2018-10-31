#include <cstdint> //using
#include <stdexcept> //std::exit

using word = uint32_t;

instruction::instruction(){
  opcod = 0;
  src_1 = 0;
  src_2 = 0;
  destn = 0;
  shift = 0;
  funct = 0;
  i_imi = 0;
  j_add = 0;
}

instruction::instruction(word inst){
  opcod = inst >> 26;
  if(is_R_type(opcod)){
    src_1 = (inst >> 21) & 0x1F;
    src_2 = (inst >> 16) & 0x1F;
    destn = (inst >> 11) & 0x1F;
    shift = (inst >> 6 ) & 0x1F;
    funct =  inst & 0x3F;
  }else if(is_I_type(opcod)){
    src_1 = (inst >> 21) & 0x1F;
    destn = (inst >> 16) & 0x1F;
    i_imi =  inst & 0xFFFF;
  }else if(is_J_type(opcod)){
    j_add =  inst & 0x3FFFFFF;
  }else{
    std::exit(-12); // opcode not found, exit with error
  }
}

bool instruction::is_R_type(int opcod){
  return opcod = 0x00;
}
bool instruction::is_I_type(int opcod){
  return opcod == 0x04||opcod == 0x05||opcod == 0x06||opcod == 0x07||opcod == 0x08||
         opcod == 0x09||opcod == 0x0A||opcod == 0x0B||opcod == 0x0C||opcod == 0x0D||
         opcod == 0x0F||opcod == 0x23||opcod == 0x24||opcod == 0x25||opcod == 0x28||
         opcod == 0x29||opcod == 0x2B;
}
bool instruction::is_J_type(int opcod){
  return opcod == 0x02 || opcod == 0x03;
}
