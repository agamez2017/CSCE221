all: Main

Main: DoublyLinkedList.o Main.o
	g++ -std=c++11 DoublyLinkedList.o Main.o -o run-dll

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -std=c++11 -c DoublyLinkedList.cpp

Main.o: Main.cpp DoublyLinkedList.h
	g++ -std=c++11 -c Main.cpp

clean:
	rm *.o run-dll
