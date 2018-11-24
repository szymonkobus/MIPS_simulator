CC = g++
CPPFLAGS = -W -Wall -std=c++11

MIPS_CC = mips-linux-gnu-gcc
MIPS_OBJCOPY = mips-linux-gnu-objcopy
MIPS_OBJDUMP = mips-linux-gnu-objdump
MIPS_CPPFLAGS = -W -Wall -O3 -fno-builtin -march=mips1 -mfp32 -fno-stack-protector
MIPS_LDFLAGS = -nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none

simulator: src/registers.o src/instruction.o src/memory.o src/cpu.o src/simulator.o
	mkdir -p bin
	$(CC) $(CPPFLAGS) src/registers.o src/instruction.o src/memory.o src/cpu.o src/simulator.o -o bin/mips_simulator
testbench: src/main.o src/parser.o src/instructionList.o
	mkdir -p bin
	cp testbench/mips_testbench bin/
	chmod +x bin/mips_testbench
	$(CC) $(CPPFLAGS) src/main.o src/parser.o src/instructionList.o -o bin/mips_parser

# Build mips_simulator
src/simulator.o: src/MIPS_Simulator/simulator.cpp
	$(CC) $(CPPFLAGS) src/MIPS_Simulator/simulator.cpp -c -o src/simulator.o
src/cpu.o: src/MIPS_Simulator/cpu.cpp src/MIPS_Simulator/cpu.hpp
	$(CC) $(CPPFLAGS) src/MIPS_Simulator/cpu.cpp -c -o src/cpu.o
src/memory.o: src/MIPS_Simulator/memory.cpp src/MIPS_Simulator/memory.hpp
	$(CC) $(CPPFLAGS) src/MIPS_Simulator/memory.cpp -c -o src/memory.o
src/instruction.o: src/MIPS_Simulator/instruction.cpp src/MIPS_Simulator/instruction.hpp
	$(CC) $(CPPFLAGS)  src/MIPS_Simulator/instruction.cpp -c -o src/instruction.o
src/registers.o: src/MIPS_Simulator/registers.cpp src/MIPS_Simulator/registers.hpp
	$(CC) $(CPPFLAGS)  src/MIPS_Simulator/registers.cpp -c -o src/registers.o

#Build MIPS_Parser_by_Olly_Larkin
src/main.o: src/MIPS_Parser_by_Olly_Larkin/main.cpp
	$(CC) $(CPPFLAGS) -c src/MIPS_Parser_by_Olly_Larkin/main.cpp -o src/main.o
src/parser.o: src/MIPS_Parser_by_Olly_Larkin/parser.cpp src/MIPS_Parser_by_Olly_Larkin/parser.hpp
	$(CC) $(CPPFLAGS) -c src/MIPS_Parser_by_Olly_Larkin/parser.cpp -o src/parser.o
src/instructionList.o: src/MIPS_Parser_by_Olly_Larkin/instructionList.cpp src/MIPS_Parser_by_Olly_Larkin/instructionList.hpp
	$(CC) $(CPPFLAGS) -c src/MIPS_Parser_by_Olly_Larkin/instructionList.cpp -o src/instructionList.o


# Compile C file (.c) into MIPS object file (.o)
%.mips.o: %.c
	$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

# Assemble MIPS assembly file (.s) into MIPS object file (.o)
%.mips.o: %.s
	$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

# Link MIPS object file (.o), producing .elf, using memory locations specified in spec
%.mips.elf: %.mips.o
	$(MIPS_CC) $(MIPS_CPPFLAGS) $(MIPS_LDFLAGS) -T src/linker.ld $< -o $@

# Extract binary instructions only from linked object file (.elf)
%.mips.bin: %.mips.elf
	$(MIPS_OBJCOPY) -O binary --only-section=.text $< $@

%.mips.s : %.mips.elf
	$(MIPS_OBJDUMP) -j .text -D $< > $@

clear:
	rm -rf bin
	rm src/*.o
	mv testbench/bin/FIB.bin testbench/	
	rm testbench/bin/*
	mv testbench/FIB.bin testbench/bin/
