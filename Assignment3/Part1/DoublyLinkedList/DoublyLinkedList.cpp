#include "DoublyLinkedList.h"
#include <exception>

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : public exception {
  virtual const char* what() const throw()
  {return "DoublyLinkedList is Empty";}
};

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
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
	DListNode* current  = dll.getFirst();
	while(current != dll.getAfterLast())
	{
		this->insertLast(current->obj);
		current = current->getNext();
	}
  }
}
// move constructor
DoublyLinkedList::DoublyLinkedList(DoublyLinkedList&& dll)
{
  DListNode* current = this->getFirst();
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

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
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
		DListNode *prev_node, *node = header.next;
		while(node != &trailer)	
		{
		prev_node = node;
		node = node->next;
		delete prev_node;
		}
		header.next = &trailer;
		trailer.prev = &header;
		DListNode* current  = dll.getFirst();
		while(current != dll.getAfterLast())
		{
		this->insertLast(current->obj);
		current = current->getNext();
		}
		return *this;
		}
  }
  if(this == &dll)
  {
	return *this;  
  }
}
// move assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(DoublyLinkedList&& dll)
{
  if(this != &dll)
  {
	  DListNode *prev_node, *node = header.next;
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
  else
  {
	  return *this;
  }
}

// insert the new object as the first one
void DoublyLinkedList::insertFirst(int newobj)
{ 
	DListNode* newNode = new DListNode(newobj, &header, header.next);
	header.next->prev = newNode;
	header.next = newNode;
}

// insert the new object as the last one
void DoublyLinkedList::insertLast(int newobj)
{
	DListNode* newNode = new DListNode(newobj,trailer.prev, &trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
}

// remove the first object from the list
int DoublyLinkedList::removeFirst()
{ 
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode* node = header.next;
	node->next->prev = &header;
	header.next = node->next;
	int obj = node->obj;
	delete node;
	return obj;
}

// remove the last object from the list
int DoublyLinkedList::removeLast()
{
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode* node = trailer.prev;
	node->prev->next = &trailer;
	trailer.prev = node->prev;
	int obj = node->obj;
	delete node;
	return obj;
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
    DListNode* prev_node, *node =header.next;
	while(node != &trailer)
	{
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev  =&header;
}

// return the first object
int DoublyLinkedList::first() const
{ 
    if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	return header.next->obj;
}

// return the last object
int DoublyLinkedList::last() const
{
    if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	return trailer.prev->obj;
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(DListNode &p, int newobj)
{
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode* newNode = new DListNode(newobj,&p,p.next);
	p.next->prev = newNode;
	p.next = newNode;
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(DListNode &p, int newobj)
{
	if(isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode* newNode = new DListNode(newobj,p.prev,&p);
	p.prev->next = newNode;
	p.prev = newNode;
}

// remove the node after the node p
int DoublyLinkedList::removeAfter(DListNode &p)
{
	if(this->isEmpty())
	{
		throw EmptyDLinkedListException();
	}
  DListNode* node = p.next;
  int obj = node->obj;
  p.next->prev = &p;
  p.next = node->next;
  delete node;
  return obj;
}

// remove the node before the node p
int DoublyLinkedList::removeBefore(DListNode &p)
{
	if(this->isEmpty())
	{
		throw EmptyDLinkedListException();
	}
	DListNode* node = p.prev;
	int obj = node->obj;
	p.prev = node->prev;
	node->prev->next =&p;
	delete node;
	return obj;
}

// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll)
{
	DListNode *current = dll.getFirst();
	int count =0;
	if(dll.isEmpty())
	{
		return 0;
	}
	else
	{
	while(current != dll.getAfterLast())
	{
		count++;
		current = current->getNext();
	}
	return count;
	}
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
	DListNode *current = dll.getFirst();
	while(current != dll.getAfterLast())
	{
		out<<current->obj<<" ";
		current = current->getNext();
	}
  return out;
}
