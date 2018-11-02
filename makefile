all: simulator.o cpu.o memory.o instruction.o registers.o
	g++ -std=c++11 -Wc++11-extensions $^ -o sim

#implicit rule
#$< variable denotes the first dependency, %.cpp here.
%.o : %.cpp %.hpp
	g++  -std=c++11 -c $<

#other variables, for information:
#$@ the target
#$^ list of all the dependencies (including the first one, denoted by $<)

run: all
	./sim

clear:
	rm *.o sim
