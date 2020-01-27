#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;
int main () {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList dll;
  cout << "list: " << dll << endl << endl;
  
  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertLast(i);
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertFirst(i);
  }
  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;
  cout << endl;
  
  //tests for insertAfter
  cout<<"Inserting After Tests\n";
  dll2.insertAfter(*(dll2.getFirst()->next->next), 45);
  cout<<"list2: after inserting 45 after the third node, "<<dll2<<endl;
  dll3.insertAfter(*(dll3.getFirst()->next->next->next->next), 89);
  cout<<"list3: after inserting 89 after the fifth node, "<<dll3<<endl;
  cout<<endl;
  
  //Test for  insertBefore
  cout<<"Inserting Before Tests\n";
  dll2.insertBefore(*(dll2.getFirst()->next->next->next->next->next), 68);
  cout<<"list2: after inserting 68 before the sixth node, "<<dll2<<endl;
  dll3.insertBefore(*(dll3.getFirst()->next->next->next->next->next->next), 17);
  cout<<"list3: after inserting 17 before the seventh node "<<dll3<<endl;
  
  
  // Tests for removeAfter
  cout<<"Remove After Tests\n";
  dll2.removeAfter(*(dll2.getFirst()->next->next));
  cout<<"list2: after removing the node after the third node, "<<dll2<<endl;
  dll3.removeAfter(*(dll3.getFirst()->next->next->next->next));
  cout<<"list3: after removing the node after the fifth node, "<<dll3<<endl;
  
  //Tests for removeBefore
  cout<<"Remove Before Tests \n";
  dll2.removeBefore(*(dll2.getFirst()->next->next));
  cout<<"list2: after removing the node before the third node, "<<dll2<<endl;
  dll3.removeBefore(*(dll3.getFirst()->next->next->next->next));
  cout<<"list3: after removing the node before the fifth node, "<<dll3<<endl;
  
  
  // Tests for DoublyLinkedListLength
  cout<<endl;
  cout<<"List length of list1: "<<DoublyLinkedListLength(dll);
  cout<<endl;
  cout<<"List length of list2: "<<DoublyLinkedListLength(dll2);
  cout<<endl;
  cout<<"List length of list3: "<<DoublyLinkedListLength(dll3);
  cout<<endl;
  cout<<endl;
  
  //Test for invalid cases 
  cout<<"Tests for invalid cases, trying to call removeFirst(), removeLast(), removeAfter(), and removeBefore() when the list is empty:\n";
  try
  {
	  DoublyLinkedList dll4;
	dll4.removeFirst();
  }
  catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
  try
  {
	 DoublyLinkedList dll4;
	dll4.removeLast();
  }
  catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
  try
  {
	  DoublyLinkedList dll4;
	dll4.removeAfter(*(dll4.getFirst()));
  }
  catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
  try
  {
	  DoublyLinkedList dll4;
	dll4.removeBefore(*(dll4.getFirst()));
  }
  catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
  
  return 0;
}
