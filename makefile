CC = g++
#CPPFLAGS = -W -Wall -std=c++11
CPPFLAGS =-std=c++11

simulator:  bin/registers.o bin/instruction.o bin/memory.o bin/cpu.o bin/simulator.o
	g++ -std=c++11 $^ -o bin/mips_simulator

#implicit rule
#$< variable denotes the first dependency, %.cpp here.

bin/simulator.o: src/simulator.cpp
	$(CC) $(CPPFLAGS) src/simulator.cpp -c -o bin/simulator.o

bin/cpu.o: src/cpu.cpp src/cpu.hpp
	$(CC) $(CPPFLAGS) src/cpu.cpp -c -o bin/cpu.o

bin/memory.o: src/memory.cpp src/memory.hpp
	$(CC) $(CPPFLAGS) src/memory.cpp -c -o bin/memory.o

bin/instruction.o: src/instruction.cpp src/instruction.hpp
	$(CC) $(CPPFLAGS)  src/instruction.cpp -c -o bin/instruction.o

bin/registers.o: src/registers.cpp src/registers.hpp
	$(CC) $(CPPFLAGS)  src/registers.cpp -c -o bin/registers.o

#bin/%.o : src/%.cpp src/%.hpp
#	g++  -std=c++11 -c $< -o bin/$<

#other variables, for information:
#$@ the target
#$^ list of all the dependencies (including the first one, denoted by $<)

run: simulator
	./bin/mips_simulator

clear:
	rm bin/*.o bin/mips_simulator
