#include "registers.hpp"

using word = uint32_t;

registers::registers(){
  for(int i = 0; i < 32; i++)
    reg[i] = 0;
}

word registers::get(int i){
  return reg[i];
}

void registers::set(int i, word data){
  if(i != 0) reg[i] = data;
}
