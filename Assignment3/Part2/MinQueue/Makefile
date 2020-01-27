all: MinQueueMain.o
	c++ -std=c++11 MinQueueMain.o -o minQueue

MinQueueMain.o: MinQueueMain.cpp TemplateMinQueue.h TemplateDoublyLinkedList.h
	g++ -std=c++11 -c MinQueueMain.cpp

clean: 
	rm *.o minQueue