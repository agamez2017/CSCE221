all: main.o
	c++ -std=c++11 main.o -o main
main.o: main.cpp  skipList.cpp skipList.h
	c++ -std=c++11 -c -g main.cpp  skipList.cpp skipList.h
clean:
	rm *.o main