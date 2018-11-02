#include "memory.hpp"
#include <fstream>

//debug
#include <iostream>

using word = uint32_t;

memory::memory(){
  data = new std::vector<word>(0 , 1);
  inst = new std::vector<word>(0x1000000 , 0);
}

memory::memory(std::string binary){
  data = new std::vector<word>(0,0);
  inst = new std::vector<word>(0x1000000 / 4 , 0);

  std::ifstream infile;
  infile.open(binary, std::ios::binary);
  char buffer[4];
  int i = 0;
  //infile.peek();
  if(infile.is_open()){
    while(!infile.eof()){
        infile.read(buffer, 4);
        infile.peek();
        word instruction = (buffer[0]<<24|buffer[1]<<16|buffer[2]<<8|buffer[3]);
        (*inst)[i] = instruction;
        i++;
        if(i > (0x1000000 / 4) ){
          std::cerr << "error: binary too long" << '\n';
          std::exit(-11);
        }
    }
  }else{
    std::cerr << "error: couldn't open binary" << '\n';
    std::exit(-11);
  }

  std::cout << "Number of instructions: " << i << '\n';
  infile.close();
}

memory::~memory(){
  delete inst;
  delete data;
}

void memory::write(word adr, word new_data){
  if(adr >= 0x20000000 && adr < 0x24000000){
    int d_adr = (adr - 0x20000000) / 4;
    std::cout<<"d_address: "<<d_adr<<std::endl;
    std::cout<<"data size: "<<data->size()<<std::endl;
    if(d_adr > data->size()){
      std::cout<<"appended memory size"<<std::endl;

      data->resize(d_adr + 1, 0);
      std::cout<<"data size: "<<data->size()<<std::endl;

    }
    (*data)[d_adr] = new_data;
  }else if( adr == 0x30000000){
    //DO STUFF
  }else{
    std::cerr << "error: trying to write to address: " << adr << '\n';
    std::exit(-11);
  }
}

word memory::read(word adr){
  if(adr >= 0x20000000 && adr < 0x24000000){
    int d_adr = (adr - 0x20000000) / 4;
    if(d_adr > data->size()) return 0;
    else return (*data)[d_adr];
  }else if( adr == 0x30000004){
    //DO STUFF
  }
  std::cerr << "error: trying to read from address: " << adr << '\n';
  std::exit(-11);
}

word memory::read_inst(int adr){
  if(adr >= 0x10000000 && adr < 0x11000000 && adr % 4 == 0){
    int i_adr = (adr - 0x10000000) / 4;
    return (*inst)[i_adr];
  }
  std::cerr << "error: trying to read instruction from address: " << adr << '\n';
  std::exit(-11);
}

void memory::print_mem() const{
  std::cout << "Instructions:" << '\n';
  for(int i = 0; i < inst->size(); i++)
    if((*inst)[i]!= 0)
      std::cout << i << "\t" << (*inst)[i] << '\n';
  std::cout << "Data:" << '\n';
  for(int i = 0; i < data->size(); i++)
    std::cout << i << "\t" << (*data)[i] << '\n';
  std::cout<<std::endl;
}
