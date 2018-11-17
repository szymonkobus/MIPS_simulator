CC = g++
CPPFLAGS = -W -Wall -std=c++11

MIPS_CC = mips-linux-gnu-gcc
MIPS_OBJCOPY = mips-linux-gnu-objcopy
MIPS_OBJDUMP = mips-linux-gnu-objdump
MIPS_CPPFLAGS = -W -Wall -O3 -fno-builtin -march=mips1 -mfp32 -fno-stack-protector
MIPS_LDFLAGS = -nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none

simulator: bin/registers.o bin/instruction.o bin/memory.o bin/cpu.o bin/simulator.o
	$(CC) $(CPPFLAGS) $^ -o bin/mips_simulator

testbench_our:
	pyinstaller --distpath bin -F -n mips_testbench testbench.py
	chmod 777 bin/mips_testbench

run: simulator testbench
	bin/mips_testbench bin/mips_simulator > wibble.csv

# Build mips_simulator
bin_exists:
	mkdir -p bin
bin/simulator.o: src/simulator.cpp | bin_exists
	$(CC) $(CPPFLAGS) src/simulator.cpp -c -o bin/simulator.o
bin/cpu.o: src/cpu.cpp src/cpu.hpp | bin_exists
	$(CC) $(CPPFLAGS) src/cpu.cpp -c -o bin/cpu.o
bin/memory.o: src/memory.cpp src/memory.hpp | bin_exists
	$(CC) $(CPPFLAGS) src/memory.cpp -c -o bin/memory.o
bin/instruction.o: src/instruction.cpp src/instruction.hpp | bin_exists
	$(CC) $(CPPFLAGS)  src/instruction.cpp -c -o bin/instruction.o
bin/registers.o: src/registers.cpp src/registers.hpp | bin_exists
	$(CC) $(CPPFLAGS)  src/registers.cpp -c -o bin/registers.o

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

rmtst:
	rm benchmark_src/tst_bench_bin/*
