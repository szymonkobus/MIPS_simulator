all: simulator.o cpu.o memory.o
	g++ -std=c++11 $^ -o sim

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
