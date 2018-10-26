all: simulator.o
	g++ simulator.o -o sim

main.o: simulator.cpp
	g++ -c simulator.cpp

run: all
	./sim

clear:
	rm *.o sim
