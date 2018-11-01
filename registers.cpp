#include "registers.hpp"

using word = uint32_t;

registers::registers(){
  for(int i = 0; i < 31; i++)
    reg[i] = 0;
}

word registers::get(int i){
  if(i == 0) return 0;
  return reg[i-1];
}

void registers::set(int i, word data){
  if(i != 0) reg[i-1] = data;
}
