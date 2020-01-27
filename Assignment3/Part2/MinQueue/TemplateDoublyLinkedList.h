#include <cstdlib>
#include <iostream>
#include <exception>
using namespace std;


struct EmptyDLinkedListException : public exception {
  virtual const char* what() const throw()
  {return "DoublyLinkedList is Empty";}
};
// list node
template<typename T>
struct DListNode
{
	T obj;
	DListNode<T> *prev, *next;
	DListNode<T>(T e=T(), DListNode<T> *p = NULL, DListNode<T> *n = NULL): obj(e), prev(p), next(n) {}
	DListNode<T>*getNext() const { return next; }
	DListNode<T>*getPrev() const { return prev; }
};

// doubly linked list
template<class T>
class DoublyLinkedList {
private:
  DListNode<T> header, trailer;
public:
  DoublyLinkedList<T>() : header(T()), trailer(T()) //  default constructor
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList<T>(const DoublyLinkedList<T>& dll); // copy constructor
  DoublyLinkedList<T>(DoublyLinkedList<T>&& dll); // move constructor
  ~DoublyLinkedList<T>(); // destructor
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator
  DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&& dll); // move assignment operator
  DListNode<T> *getFirst() const { return header.next; } // return the pointer to the first node
  const DListNode<T> *getAfterLast() const { return &trailer; }  // return the pointer to the trailer
  bool isEmpty() const { return header.next == &trailer; }// return if the list is empty
  T first() const; // return the first object
  T last() const; // return the last object
  void insertFirst(T newobj); // insert to the first of the list
  T removeFirst(); // remove the first node
  void insertLast(T newobj); // insert to the last of the list
  T removeLast(); // remove the last node
  void insertAfter(DListNode<T>&p, T newobj);//insert new obj after the specified node
  void insertBefore(DListNode<T> &p, T newobj);//insert new obj before the specified node
  T removeAfter(DListNode<T> &p);//remove the node after the specified node
  T removeBefore(DListNode<T> &p);//remove the node before the specified node
};
// output operator
template<typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);
// return the list length
template<typename T>
int DoublyLinkedListLength(DoublyLinkedList<T>& dll);


template<typename T> //copy constructor
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
  if(dll.isEmpty())
  {
  header.next = &trailer;
  trailer.prev = &header;
  }
  else
  {
	header.next = &trailer;
	trailer.prev = &header;
	DListNode<T>* current  = dll.getFirst();
	while(current != dll.getAfterLast())
	{
		this->insertLast(current->obj);
		current = current->getNext();
	}
  }
}

template<typename T> //move constructor
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& dll)
{
  DListNode<T>* current = this->getFirst();
  while(current != this->getAfterLast());
  {
	  current = current->next;
	  delete current->prev;
  }
  delete current;
  header = dll.header;
  trailer= dll.trailer;
  header.next = dll.header.next;
  trailer.prev = dll.trailer.prev;
  dll.header.next = nullptr;
  dll.trailer.prev = nullptr;
}

template<typename T> //assignment operator
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
  if(this != &dll)
  {
	  if(dll.isEmpty())
	  {
		  header.next = &trailer;
		  trailer.prev = &header;
		  return *this;
	  }
	  else
	  {
		DListNode<T> *prev_node, *node = header.next;
		while(node != &trailer)	
		{
		prev_node = node;
		node = node->next;
		delete prev_node;
		}
		header.next = &trailer;
		trailer.prev = &header;
		DListNode<T>* current  = dll.getFirst();
		while(current != dll.getAfterLast())
		{
		this->insertLast(current->obj);
		current = current->getNext();
		}
		return *this;
		}
  }
}

template<typename T> //move assignment operator
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& dll)
{
  if(this != &dll)
  {
	  DListNode<T> *prev_node, *node = header.next;
	  while(node != &trailer)	
	  {
		prev_node = node;
		node = node->next;
		delete prev_node;
	  }
	  header.next = &trailer;
	  trailer.prev = &header;
	  header.next = dll.header.next;
	  trailer.prev = dll.trailer.prev;
	  dll.header.next = nullptr;
	  dll.trailer.prev = nullptr;
	  return *this;
  }
}

template<typename T> // insert the new object as the first one
void DoublyLinkedList<T>::insertFirst(T newobj)
{ 
	DListNode<T>* newNode = new DListNode<T>(newobj, &header, header.next);
	header.next->prev = newNode;
	header.next = newNode;
}

template<typename T>// insert new object as the last one
void DoublyLinkedList<T>::insertLast(T newobj)
{
	DListNode<T>* newNode = new DListNode<T>(newobj,trailer.prev, &trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
}

template<typename T>//remove the first object from the list
T DoublyLinkedList<T>::removeFirst()
{ 
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode<T>* node = header.next;
	node->next->prev = &header;
	header.next = node->next;
	T obj = node->obj;
	delete node;
	return obj;
}

template<typename T>//remove the last object from the list
T DoublyLinkedList<T>::removeLast()
{
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode<T>* node = trailer.prev;
	node->prev->next = &trailer;
	trailer.prev = node->prev;
	T obj = node->obj;
	delete node;
	return obj;
}

template<typename T> //destructor
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DListNode<T>* prev_node, *node =header.next;
	while(node != &trailer)
	{
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev  =&header;
}

template<typename T> // return the first object
T DoublyLinkedList<T>::first() const
{ 
    if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	return header.next->obj;
}

template<typename T> // return the last object
T DoublyLinkedList<T>::last() const
{
    if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	return trailer.prev->obj;
}

template<typename T>//insert the new object after the node p
void DoublyLinkedList<T>::insertAfter(DListNode<T> &p, T newobj)
{
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode<T>* newNode = new DListNode<T>(newobj,&p,p.next);
	p.next->prev = newNode;
	p.next = newNode;
}

template<typename T>//insert the new object before the node p
void DoublyLinkedList<T>::insertBefore(DListNode<T> &p, T newobj)
{
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode<T>* newNode = new DListNode<T>(newobj,p.prev,&p);
	p.prev->next = newNode;
	p.prev = newNode;
}

template<typename T>// remove the node after the node p
T DoublyLinkedList<T>::removeAfter(DListNode<T> &p)
{
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
  DListNode<T>* node = p.next;
  T obj = node->obj;
  p.next->prev = &p;
  p.next = node->next;
  delete node;
  return obj;
}

template<typename T>//remove the node before the node p
T DoublyLinkedList<T>::removeBefore(DListNode<T> &p)
{
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode<T>* node = p.prev;
	T obj = node->obj;
	p.prev = node->prev;
	node->prev->next =&p;
	delete node;
	return obj;
}
 template<typename T>
int DoublyLinkedListLength(DoublyLinkedList<T>& dll) //return the list length
{
	DListNode<T> *current = dll.getFirst();
	int count =0;
	while(current != dll.getAfterLast())
	{
		count++;
		current = current->getNext();
	}
	return count;
}

// output operator
template<typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
	DListNode<T> *current = dll.getFirst();
	while(current != dll.getAfterLast())
	{
		out<<current->obj<<" ";
		current = current->getNext();
	}
  return out;
}