#include <cstdint> //using
#include <stdexcept> //std::exit

using op_type = uint8_t;
using reg_type = uint8_t;
using shift_type = uint8_t;
using funct_type = uint8_t;
using imm_type = uint16_t;
using jadd_type = uint32_t;
using word_type = uint32_t;


struct R_type_instruction{
    op_type opcode;
    reg_type src_reg1;
    reg_type src_reg2;
    reg_type dest_reg;
    shift_type shift;
    funct_type funct;
};

struct I_type_instruction{
    op_type opcode;
    reg_type src_reg;
    reg_type dest_reg;
    imm_type imm;
};

struct J_type_instruction{
    op_type opcode;
    jadd_type j_address;
};

struct Instruction{
    //0 - R_type_instruction
    //1 - I_type_instruction
    //2 - J_type_instruction
    int choose;
    R_type_instruction r_inst;
    I_type_instruction i_inst;
    J_type_instruction j_inst;



};

R_type_instruction create_R_type_instruction(word_type word){
    R_type_instruction instruction;
    instruction.opcode = op_type(word>>26);
    instruction.src_reg1 = reg_type((word & 0x3E00000)>>21);
    instruction.src_reg2 = reg_type((word & 0x1F0000)>>16);
    instruction.dest_reg = reg_type((word & 0xF800)>>11);
    instruction.shift = shift_type((word & 0x7C0)>>6);
    instruction.funct = funct_type(word & 0x3F)
    return instruction;
}

I_type_instruction create_I_type_instruction(word_type word){
    I_type_instruction instruction;
    instruction.opcode = op_type(word>>26);
    instruction.src_reg = reg_type((word & 0x3E00000)>>21);
    instruction.dest_reg = reg_type((word & 0x1F0000)>>16);
    instruction.imm = imm_type(word & 0xFFFF);
    return instruction;
}

J_type_instruction create_J_type_instruction(word_type word){
    J_type_instruction instruction;
    instruction.opcode = op_type(word>>26);
    instruction.j_address = jadd_type(word & 0x3FFFFFF);
    return instruction;
}


Instruction decode(word_type in_word){
    //0 - R_type_instruction
    //1 - I_type_instruction
    //2 - J_type_instruction
    Instruction instruction;

    op_type opcode = op_type(in_word>>26);

    if(opcode == 0x00){
        instruction.choose = 0;
        instruction.r_inst = create_R_type_instruction(in_word);
    }
    else if(opcode == 0x04||0x05||0x06||0x07||0x08||0x09||0x0A||0x0B||0x0C||0x0D||0x0F||0x23||0x24||0x25||0x28||0x29||0x2B){
        instruction.choose = 1;
        instruction.i_inst = create_I_type_instruction(in_word);
    }
    else if(opcode == 0x02||0x03){
        instruction.choose = 2;
        instruction.j_inst = create_J_type_instruction(in_word);
    }
    else{
        // opcode not found, exit with error
        std::exit(-12);
    }

    return instruction;
    //when executing the instruction do switch statement on instruction.choose and have 3 seperate execure_i/execute_j/execute_r functions
    //void execute(const Instruction instruction)
}
