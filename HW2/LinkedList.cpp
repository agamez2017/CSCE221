#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int elem=0, Node* ptr= NULL):data(elem), next(ptr){}; 
	Node* getNext() const {return next;}
};

class LinkedList
{
	private:
		Node* header, trailer;
	public:
		LinkedList():header(0),trailer(0)
		{header->next = &trailer;}
		~LinkedList()
		{
			Node* prev_node, *node = header->next;
			while(node != &trailer)
			{
				prev_node= node;
				node = node->next;
				delete prev_node;
			}
			header->next = &trailer;
		}
		void insertFirst(int elem)
		{
			cout<<"fucnL";
			Node* newNode = new Node(elem);
			newNode->next = header->next;
			header->next = newNode;
		}
		bool isEmpty(){return header->next ==&trailer;}
		void print()
		{
			cout<<"dang";
			Node* temp = header;
			while(temp != &trailer)
			{
				cout<<temp->data<<" ";
				temp = temp->getNext();
			}
		}
		int numberOfNodes(Node* temp)
		{
			if(temp == &trailer )
			{
				return 0;
			}
			else
			{
				return 1+numberOfNodes(temp->getNext());
			}
		}
		
};

int main()
{
	LinkedList ll1;
	for(int i=0;i<10;i++)
	{
		ll1.insertFirst(i);
	}
	ll1.print();
	
	
}
