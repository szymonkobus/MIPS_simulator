#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"


int main(int argc, char const *argv[]) {
  //cpu c();
  //std::string bin = argv[1];
  memory m;

  std::cout << m.inst->size() << '\n';
  std::cout << m.data->size() << '\n';

  memory m2("bin_tst1.bin");

  std::cout << "m" << '\n';
  m.print_mem();

  std::cout << "m2" << '\n';
  m2.print_mem();

  //c.run(m2);

  return 0;
}
