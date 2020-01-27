#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <limits>
#include <ctime>
#include <random>
#include <fstream>
using namespace std;


struct Node{ 	
	int value;
	list<Node>::iterator down;
	Node(int x, list<Node>::iterator some): value(x),down(some){};// constructor
};

class Skiplist{//max level 10;
	private:
	vector<list<Node>> structure;
	int numOfNodes=0; //number of nodes
	double numofCompForInsertion=0;
	double numofCompForSearch=0;
	double numofCompForDeletion=0;
	double numofInsertionops=0;
	double numofSearchops=0;
	double numofDeletionops=0;
	public:
	Skiplist();
	void insert(int x);//insert function
	bool search(int x);//search function
	int coinFlip();//for number of levels inserted
	void remove(int x);//deletion 
	void printSkipList();//printing the structure;
	void removeAll();//will simply call the remove function for all nodes
	int get_numOfNodes() const{return numOfNodes;};
	double averageInsertionCost()const{return numofCompForInsertion/numofInsertionops;}//will calculate the
	double averageDeletionCost();
	double averageSearchCost();
};

istream& operator>>(istream& in, Skiplist& sklist); //input operator

ostream& operator<<(ostream& out, Node& node);//ouput operator for nodes

#endif