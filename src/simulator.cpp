#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"

int main(int argc, char const *argv[]) {
  cpu c("MIPS_bin/bin_tst10.bin");

  std::cerr << "cpu mem: " << "\n";
  c.m.print_mem();
  c.test_fill();
  std::cerr << "cpu registers initial"<<std::endl;
  c.reg_print(1);

  c.run();

  return 0;
}
