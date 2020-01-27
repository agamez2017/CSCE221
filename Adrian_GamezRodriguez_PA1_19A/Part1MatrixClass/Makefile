all: My_matrix.o main.o
	c++ -std=c++11 My_matrix.o main.o -o main
My_matrix.o: My_matrix.cpp My_matrix.h
	c++ -std=c++11 -c -g My_matrix.cpp
main.o: main.cpp My_matrix.h
	c++ -std=c++11 -c -g main.cpp
clean:
	rm *.o main
