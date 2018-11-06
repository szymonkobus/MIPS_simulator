#include <iostream>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"

int main(int argc, char const *argv[]) {
  std::string name_bin = "MIPS_bin/bin_tst10.bin";

  if(argc >= 2) name_bin = argv[1];
  cpu c(name_bin);

  c.run();

  return 0;
}
