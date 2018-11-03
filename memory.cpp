#include "memory.hpp"
#include <fstream>
//#include <cstdint> //using


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
  char buffer[4]{0};
  int i = 0;
  //infile.peek();
  if(infile.is_open()){
    while(!infile.eof()){
        infile.read(buffer, 4);
        infile.peek();
        word instruction = 0;
        instruction = (static_cast<uint8_t>(buffer[0])<<24|static_cast<uint8_t>(buffer[1])<<16|static_cast<uint8_t>(buffer[2])<<8|static_cast<uint8_t>(buffer[3]));        
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

  std::cerr << "Number of instructions: " << i << '\n';
  infile.close();
}

memory::~memory(){
  delete inst;
  delete data;
}

void memory::write_w(word adr, word new_data){
  if(adr >= 0x20000000 && adr < 0x24000000 && adr % 4 == 0){
    int index = (adr - 0x20000000) >> 2;
    if(index >= data->size()){
      data->resize(index + 1, 0);
    }
    (*data)[index] = new_data;
  }else if(adr == 0x30000000 && adr % 4 == 0){
    // TODO: test
    std::putchar(new_data & 0xFF);
  }else{
    std::cerr << "error: trying to write_word to address: " << adr << '\n';
    std::exit(-11);
  }
}

void memory::write_h(word adr, word new_data){
  if(adr >= 0x20000000 && adr < 0x24000000 && adr % 2 == 0){
    int index = (adr - 0x20000000) >> 2;
    if(index >= data->size()){
      data->resize(index + 1, 0);
    }
    word old_data = (*data)[index];

    word combined_data;
    if(adr & 0x2) combined_data = (old_data & 0x0000FFFF) | (new_data << 16);
    else          combined_data = (old_data & 0xFFFF0000) | new_data;

    (*data)[index] = combined_data;
  }else if(adr == 0x30000000 && adr % 2 == 0){
    // TODO: test
    if(adr % 4 == 0) std::putchar(new_data & 0xF);
    else std::putchar(0);
  }else{
    std::cerr << "error: trying to write_half to address: " << adr << '\n';
    std::exit(-11);
  }
}

void memory::write_b(word adr, word new_data){
  if(adr >= 0x20000000 && adr < 0x24000000){
    int index = (adr - 0x20000000) >> 2;
    if(index >= data->size()){
      data->resize(index + 1, 0);
    }
    word old_data = (*data)[index];

    word combined_data;
    if(adr & 0x3) combined_data = (old_data & 0x00FFFFFF) | (new_data << 24);
    if(adr & 0x2) combined_data = (old_data & 0xFF00FFFF) | (new_data << 16);
    if(adr & 0x1) combined_data = (old_data & 0xFFFF00FF) | (new_data <<  8);
    else          combined_data = (old_data & 0xFFFFFF00) | new_data;

    (*data)[index] = combined_data;
  }else if(adr == 0x30000000){
    // TODO: test
    if(adr % 4 == 0) std::putchar(new_data & 0xF);
    else std::putchar(0);
  }else{
    std::cerr << "error: trying to write_byte to address: " << adr << '\n';
    std::exit(-11);
  }
}

word memory::read_w(word adr){
  if(adr >= 0x20000000 && adr < 0x24000000 && adr % 4 == 0){
    int index = (adr - 0x20000000) / 4;
    if(index > data->size()) return 0;
    else return (*data)[index];
  }else if( adr == 0x30000004 && adr % 4 == 0){
    return std::getchar();
  }
  std::cerr << "error: trying to read from address: " << adr << '\n';
  std::exit(-11);
 }

word memory::read_h(word adr){
  if(adr >= 0x20000000 && adr < 0x24000000 && adr % 2 == 0){
    int index = (adr - 0x20000000) / 4;
    if(index > data->size()) return 0;

    word word_data = (*data)[index];
    if(adr & 0x2) return (word_data & 0xFFFF0000) >> 16;
    else          return (word_data & 0x0000FFFF);

  }else if(adr == 0x30000004  && adr % 2 == 0){
    if(adr % 4 == 0) return std::getchar();
    std::getchar();
    return 0;
  }
  std::cerr << "error: trying to read from address: " << adr << '\n';
  std::exit(-11);
}

word memory::read_b(word adr){
  if(adr >= 0x20000000 && adr < 0x24000000 && adr % 2 == 0){
    int index = (adr - 0x20000000) / 4;
    if(index > data->size()) return 0;

    word word_data = (*data)[index];
    if(adr & 0x3) return (word_data & 0xFF000000) >> 24;
    if(adr & 0x3) return (word_data & 0x00FF0000) >> 16;
    if(adr & 0x3) return (word_data & 0x0000FF00) >> 8;
    else          return (word_data & 0x000000FF);

  }else if(adr == 0x30000004  && adr % 2 == 0){
    if(adr % 4 == 0) return std::getchar();
    std::getchar();
    return 0;
  }
  std::cerr << "error: trying to read from address: " << adr << '\n';
  std::exit(-11);
}

word memory::read_inst(int adr){
  if(adr >= 0x10000000 && adr < 0x11000000 && adr % 4 == 0){
    int index = (adr - 0x10000000) / 4;
    return (*inst)[index];
  }
  std::cerr << "error: trying to read instruction from address: " << adr << '\n';
  std::exit(-11);
}

void memory::print_mem() const{
  std::cerr << "Instructions:" << '\n';
  for(int i = 0; i < inst->size(); i++)
    if((*inst)[i]!= 0)
      std::cerr << i << "\t" << (*inst)[i] << '\n';
  std::cerr << "Data:" << '\n';
  for(int i = 0; i < data->size(); i++)
    std::cerr << i << "\t" << (*data)[i] << '\n';
  std::cerr<<std::endl;
}
