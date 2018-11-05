#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"

int main(int argc, char const *argv[]) {
  std::string name_bin = "MIPS_bin/out_bin.bin";

  if(argc == 2) name_bin = argv[1];
  cpu c(name_bin);

  //c.test_fill();

  c.run();

  return 0;
}
