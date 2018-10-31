#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <string>
#include <vector>

using word = uint32_t;

class memory{
public:
  std::vector<word>* inst;
  std::vector<word>* data;

public:
  memory();
  memory(std::string binary);
  ~memory();
  void write(word adr, word new_data);
  word read(word address);
  word read_inst(int address);

  void print_mem() const;
};

#endif
