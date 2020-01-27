#include <cstdlib>
#include <iostream>
using namespace std;
class DoublyLinkedList; // class declaration

// list node
struct DListNode {
  int obj;
  DListNode *prev, *next;
  DListNode(int e=0, DListNode *p = NULL, DListNode *n = NULL)
    : obj(e), prev(p), next(n) {}
	DListNode*getNext() const { return next; }
	DListNode*getPrev() const { return prev; }
};

// doubly linked list
class DoublyLinkedList {
private:
  DListNode header, trailer;
public:
  DoublyLinkedList() : header(0), trailer(0) // constructor
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList(const DoublyLinkedList& dll); // copy constructor
  DoublyLinkedList(DoublyLinkedList&& dll); // move constructor
  ~DoublyLinkedList(); // destructor
  DoublyLinkedList& operator=(const DoublyLinkedList& dll); // assignment operator
  DoublyLinkedList& operator=(DoublyLinkedList&& dll); // move assignment operator
  DListNode *getFirst() const { return header.next; } // return the pointer to the first node
  const DListNode *getAfterLast() const { return &trailer; }  // return the pointer to the trailer
  bool isEmpty() const { return header.next == &trailer; }  // return if the list is empty
  int first() const; // return the first object
  int last() const; // return the last object
  void insertFirst(int newobj); // insert to the first of the list
  int removeFirst(); // remove the first node
  void insertLast(int newobj); // insert to the last of the list
  int removeLast(); // remove the last node
  void insertAfter(DListNode &p, int newobj);//insert new obj after the specified node
  void insertBefore(DListNode &p, int newobj);//insert new obj before the specifid node
  int removeAfter(DListNode &p);//remove the node after the specified node
  int removeBefore(DListNode &p);//remove the node before the specified node
};

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll);
// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll);
