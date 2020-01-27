#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int e=0, Node* n= NULL): data(e), next(n) {}
	Node* getNext() const {return next;}
	
};

int numberofNodes(Node* temp)
{
	if(temp == NULL)//base case
	{
		return 0;
	}
	else
	{
		return 1 + numberofNodes(temp->next);
	}
}
class SinglyLinkedList
{
	public:
		int size;
		Node* header;
		SinglyLinkedList();
		~SinglyLinkedList();
		void insert(int elem);
		void print();
		int callNumberofNodes() {return numberofNodes(header);}
};

SinglyLinkedList::SinglyLinkedList()
{
	this->header = NULL;
	size =0;//just to check against the recursive function
}

SinglyLinkedList::~SinglyLinkedList()
{
}

void SinglyLinkedList::insert(int elem)
{
	Node* newNode =new Node(elem);
	newNode->next = this->header;
	this->header = newNode;
	this->size++;
}

void SinglyLinkedList::print()
{
	Node* current = this->header;
	while(current)
	{
		cout<<current->data<<" ";
		current = current->next;
	}
	
}

int main()
{
	//Testing a Singly Linked List that has 20 elements
	SinglyLinkedList L1;
	for(int i=0; i<20; i++)
	{
		L1.insert(i);
	}
	cout<<"L1: ";
	L1.print();
	cout<<endl;
	cout<<"Size of L1: "<<L1.callNumberofNodes();
	cout<<endl;
	
	//Testing a Singly Linked List with 0 elements
	SinglyLinkedList L2;
	cout<<"L2: ";
	L2.print();
	cout<<endl;
	cout<<"Size of L2: "<<L2.callNumberofNodes();
	cout<<endl;
	
	
}