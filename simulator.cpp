#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"

int main(int argc, char const *argv[]) {
  cpu c("./bin/bin_tst5.bin");

  std::cout << "cpu mem: " << "\n";
  c.m.print_mem();
  c.test_fill();

  c.run();

  return 0;
}
