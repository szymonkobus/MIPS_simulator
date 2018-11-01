#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"


int main(int argc, char const *argv[]) {
  //cpu c("bin_tst1.bin");
  //std::string bin = argv[1];
  memory m2("bin_tst2.bin");

  std::cout << "m2" << '\n';
  m2.print_mem();

  return 0;
}
