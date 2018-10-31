using word = uint32_t;

class cpu{
private:
  //reg[0] == 0
  word reg[31];
  word pc;
public:
  cpu(int w);
  void run(memory& m);
private:
  //instructions
};
