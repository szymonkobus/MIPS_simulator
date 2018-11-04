#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"

int main(int argc, char const *argv[]) {
<<<<<<< HEAD:simulator.cpp

  cpu c("./bin/bin_tst11.bin");
=======
  cpu c("MIPS_bin/bin_tst10.bin");
>>>>>>> 96f0c1d0a4287710346e1535752328d72eaafc3c:src/simulator.cpp

  std::cerr << "cpu mem: " << "\n";
  c.m.print_mem();
  c.test_fill();
  std::cerr << "cpu registers initial"<<std::endl;
  c.reg_print(1);

  c.run();

  return 0;
}
