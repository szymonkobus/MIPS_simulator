#include <string>

using word = uint32_t;

class memory{
private:
  int a;
public:
  memory(std::string binary);
  memory();

  word read(int address);
  void write(int address);
  word read_inst(int address);
};
