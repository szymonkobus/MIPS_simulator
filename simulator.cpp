#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"

int main(int argc, char const *argv[]) {

  memory m2("bin_tst3.bin");

  //std::cout << "m2" << '\n';
  //m2.print_mem();

<<<<<<< HEAD
  cpu c("bin_tst2.bin");

  //std::cout << "cpu mem: " << "\n";
  //c.m.print_mem();

=======
  cpu c("bin_tst3.bin");
  std::cout << "cpu mem: " << "\n";
  c.m.print_mem();
  c.test_fill();
  c.reg_print();
>>>>>>> a3f9539582abd8289daae68f61739c4a322774f9
  c.run();

  return 0;
}
