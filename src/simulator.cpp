#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"

int main(int argc, char const *argv[]) {
  std::string name_bin = "MIPS_bin/out_bin.bin";

  if(argc == 2) name_bin = argv[1];
  cpu c(name_bin);

  std::cerr << "cpu mem: " << "\n";
  c.m.print_mem();
  c.test_fill();
  std::cerr << "cpu registers initial"<<std::endl;
  c.reg_print(1);

  c.run();

  return 0;
}
