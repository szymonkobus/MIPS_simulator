#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"

int main(int argc, char const *argv[]) {

  memory m2("bin_tst2.bin");

  //std::cout << "m2" << '\n';
  //m2.print_mem();

  cpu c("bin_tst2.bin");

  //std::cout << "cpu mem: " << "\n";
  //c.m.print_mem();

  c.run();

  return 0;
}
