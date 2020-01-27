#include <iostream>
#include <time.h>
#include "TemplateMinQueue.h"
using namespace std;

int main()
{
	
	srand(time(NULL));//for generating random ints
	
	
	//NOTE my dequeue is O(n) which mean the queue is not sorted,
	//rather I search for the minimum 
	
	//Creating MinQueue object
	MinQueue<int> minQ1;
	cout<<"After creating a MinQueue object with type int\nminQ1: ";
	cout<<minQ1;
	cout<<endl;
	cout<<"Is minQ1 empty? :";
	cout<<minQ1.isEmpty();
	cout<<endl;
	cout<<endl;
	
	//Testing Enqueue with random numbers to enqueue.
	cout<<"Inputing 10 random intergers of range 0-100 into the queue:\n";
	for(int i= 0; i<10;i++)
	{
		int random = rand()%100;
		minQ1.enqueue(random);
	}
	cout<<"minQ1: ";
	cout<<minQ1;
	cout<<endl;
	cout<<endl;
	
	//Testing size function
	cout<<"The size of the min priority queue is: ";
	cout<<minQ1.size();
	cout<<endl;
	cout<<endl;
	
	
	//Testing the min() function
	cout<<"The minimum of minQ1 is: ";
	cout<<minQ1.min();
	cout<<endl;
	cout<<endl;
	
	
	//Testing the dequeue function
	cout<<"The minQ1 after removing the minimum node :";
	minQ1.dequeue();
	cout<<minQ1;
	cout<<endl;
	cout<<"Size of queue: ";
	cout<<minQ1.size();
	cout<<endl;
	cout<<endl;
	
	//Testing the isEmpty() function
	cout<<"Is the minQ1 empty?: ";
	cout<<minQ1.isEmpty();
	cout<<endl;
	cout<<endl;
	
	
	//Some invalid test cases
	cout<<"Create new object called minQ2\n";
	MinQueue<int> minQ2;
	cout<<"minQ2: ";
	cout<<minQ2;
	cout<<endl;
	cout<<endl;
	cout<<"Testing invalid cases, calling dequeue and min when list is empty:\n";
	try
	{
		minQ2.min();
	}catch(exception &error){cerr<<"Error: "<<error.what();}
	cout<<endl;
	try
	{
		minQ2.dequeue();
	}catch(exception &error){cerr<<"Error: "<<error.what();}
	
	return 0;
	
}