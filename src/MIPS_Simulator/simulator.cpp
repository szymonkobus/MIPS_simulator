#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"

int main(int argc, char const *argv[]) {
  std::string name_bin = "MIPS_bin/out_bin.bin";

  if(argc == 2) name_bin = argv[1];
  else{
    std::cout<<"binary not found"<<std::endl;
    exit(-21);
  }

  cpu c(name_bin);

  c.run();

  return 0;
}
