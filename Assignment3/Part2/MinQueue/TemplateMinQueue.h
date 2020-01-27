#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
using namespace std;
template<typename T>
class MinQueue
{
	private:
		DoublyLinkedList<T> minQ; //DLL for queue
		int sz=0; //size
		int mn;
	public:
		MinQueue<T>():minQ(){} //default constructor
		T min() const;//return minimum in queue
		string isEmpty() const;//is the queue empty
		int size() const {return sz;}//return size of the queue
		void dequeue();//remove the minimum node
		void enqueue(T newobj);//insert new object into the queue
		DoublyLinkedList<T> getMinQ() const {return minQ;}//helper function for operator <<
		
};

template<typename T>//print out minQ 
ostream& operator<<(ostream& out, const MinQueue<T>& obj)
{
	DoublyLinkedList<T> temp = obj.getMinQ();
	DListNode<T> *current = temp.getFirst();
	while(current != temp.getAfterLast())
	{
		out<<current->obj<<" ";
		current = current->getNext();
	}
  return out;
}

template<typename T>
T MinQueue<T>::min()const //O(n) b/c it traverses through list to find min
{
	if(minQ.isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	else
	{
		DListNode<T>* current = minQ.getFirst();
		T min =current->obj;
		while(current != minQ.getAfterLast())
		{
			if(current->obj <= min)
			{
				min = current->obj;
			}
			current= current->next;
		}
		return min;
		}
}

template<typename T>
string MinQueue<T>::isEmpty()const
{
	string isEmpty = "False";
	if(minQ.isEmpty())
	{
		isEmpty = "True";
	}
	return isEmpty;
}
template<typename T>
void MinQueue<T>::dequeue()//O(n) bc it traverses through the 
{
	if(minQ.isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	else
	{
		DListNode<T>* current = minQ.getFirst();
		DListNode<T>* min = current;
		while(current != minQ.getAfterLast())
		{
			if(current->obj <= min->obj)
			{
				min = current;
				mn= min->obj;
			}
			current= current->next;
		}
		minQ.removeAfter(*(min->prev));
	}
	sz--;
}

template<typename T>
void MinQueue<T>::enqueue(T e)//O(1)
{
	minQ.insertLast(e);
	sz++;
}