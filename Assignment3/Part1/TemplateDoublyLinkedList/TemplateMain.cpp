#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main () {
	
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DoublyLinkedList<string> dll;
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertLast(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertFirst(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList<string> dll3;
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

  // more testing...
  // add tests for insertAfter,
  cout<<"Inserting After\n";
  dll2.insertAfter(*(dll2.getFirst()->next->next), "HOWDY");
  cout<<"list2: after inserting 'HOWDY' after the third node, "<<dll2<<endl;
  dll3.insertAfter(*(dll3.getFirst()->next->next->next->next), "GIG EM");
  cout<<"list3: after inserting 'GIG EM' after the fifth node, "<<dll3<<endl;
  cout<<endl;
  
  //Test for  insertBefore
  cout<<"Inserting Before\n";
  dll2.insertBefore(*(dll2.getFirst()->next->next->next->next->next), "HEY");
  cout<<"list2: after inserting 'HEY' before the sixth node, "<<dll2<<endl;
  dll3.insertBefore(*(dll3.getFirst()->next->next->next->next->next->next), "AHHH");
  cout<<"list3: after inserting 'AHHH' before the seventh node "<<dll3<<endl;
  
  // Tests for removeAfter
  cout<<"Remove After\n";
  dll2.removeAfter(*(dll2.getFirst()->next->next));
  cout<<"list2: after removing the node after the third node, "<<dll2<<endl;
  dll3.removeAfter(*(dll3.getFirst()->next->next->next->next));
  cout<<"list3: after removing the node after the fifth node, "<<dll3<<endl;
  
  //Tests for removeBefore
  cout<<"Remove Before \n";
  dll2.removeBefore(*(dll2.getFirst()->next->next));
  cout<<"list2: after removing the node before the third node, "<<dll2<<endl;
  dll3.removeBefore(*(dll3.getFirst()->next->next->next->next));
  cout<<"list3: after removing the node before the fifth node, "<<dll3<<endl;
  cout<<endl;
  
   // Tests for DoublyLinkedListLength
  cout<<"List length of list1: "<<DoublyLinkedListLength(dll);
  cout<<endl;
  cout<<"List length of list2: "<<DoublyLinkedListLength(dll2);
  cout<<endl;
  cout<<"List length of list3: "<<DoublyLinkedListLength(dll3);
  cout<<endl;
  cout<<endl;
  //Some Invalid cases
  
  cout<<"Some invalid cases that call removeFirst(), removeLast(), removeAfter(), and removeBefore(): when the list is empty\n";
  try
  {
	  DoublyLinkedList<string> dll4;
	  dll4.removeFirst();
  }
  catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
  try
  {
	  DoublyLinkedList<string> dll4;
	  dll4.removeLast();
  }
  catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
  try
  {
	  DoublyLinkedList<string> dll4;
	  dll4.removeAfter(*(dll4.getFirst()));
  }
  catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
  try
  {
	  DoublyLinkedList<string> dll4;
	  dll4.removeBefore(*(dll4.getFirst()));
  }
  catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
  
 return 0;
}
