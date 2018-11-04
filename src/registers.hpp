#ifndef REGISTERS_HPP
#define REGISTERS_HPP
#include <cstdint>

using word = uint32_t;

class registers{
private:
  word reg[32];
public:
  registers();
  word get(int i);
  void set(int i, word data);
};

#endif
