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

  return 0;
}
