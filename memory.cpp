#include "memory.hpp"
#include <fstream>

using word = uint32_t;

memory::memory(){
  data = new std::vector<word>(0,0);
  inst = new std::vector<word>(0x1000000,0);

}

memory::memory(std::string binary){
  data = new std::vector<word>(0,0);
  inst = new std::vector<word>(0x1000000,0);

  std::ifstream infile;
  infile.open("binary.bin", std::ios::binary);
  buffer char[4];
  infile.read(buffer, 4);
  int i = 0;
  while(!infile.eof()){
      infile.read(buffer, 4);
      infile.peek();
      word instruction = (buffer[0]<<24|buffer[1]<<16|buffer[2]<<8|buffer[3]);
      inst[i] = instruction
      i++;
  }
}

memory::~memory(){
  delete inst;
  delete data;
}

//write

word memory::read(int adr){
  if(adr >= 0x20000000 && adr < 0x24000000){
    int d_adr = (adr - 0x20000000) / 4;
    if(d_adr > data.size()) return 0;
    else return (*data)[d_adr];
  }
  // TODO: ADDR_GETC

  // TODO: ERROR
  return 0;
}

word memory::read_inst(int adr){
  if(adr >= 0x10000000 && adr < 0x11000000){
    int i_adr = adr - 0x10000000;
    return (*data)[i_adr];
  }
  // TODO: ERROR
}
