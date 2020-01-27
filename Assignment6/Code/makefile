all: main.o
	c++ -std=c++11 main.o -o main
main.o: main.cpp drawGraph.cpp drawGraph.h
	c++ -std=c++11 -c -g main.cpp drawGraph.cpp drawGraph.h
clean: 
	rm *.o main