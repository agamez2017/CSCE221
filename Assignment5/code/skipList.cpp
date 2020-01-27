#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <limits>
#include <ctime>
#include <random>
#include <fstream>
#include "skipList.h"

using namespace std;

Skiplist::Skiplist()//constructor
{
	list<Node>::iterator listiterator;//for the iteration of each list
	list<Node> ll;
	structure.push_back(ll);
	Node negNode(numeric_limits<int>::min(), structure[0].end());//making the negative infinity node
	Node posNode(numeric_limits<int>::max(),structure[0].end());//making the positive infinity node
	structure[0].push_back(negNode);
	structure[0].push_back(posNode);
	
	for(int i=1;i<10;i++)//for other 9 rows
	{
		Node negNode(numeric_limits<int>::min(),structure[i-1].begin());//making the negative infinity node
		Node posNode(numeric_limits<int>::max(),--structure[i-1].end());//making the positive infinity node
		structure.push_back(ll);//push back that list of nodes in the vector
		structure[i].push_back(negNode);//push back the negative infinity node into every list
		structure[i].push_back(posNode);//push back the positive infinity node into every list
	}
	
}

int Skiplist::coinFlip()//generates random number of times of insertion
{
	int numofHeads=0;
	int heads;
	do
	{
		heads = rand()%2;
		if(heads ==1)
		{
			numofHeads++;
		}
	}while(heads ==1);
	if(numofHeads>9)//safety guard
	{
		numofHeads =9;
	}
	return numofHeads;
}

void Skiplist::printSkipList()
{
	if(numOfNodes <=16)
	{
	list<Node>::iterator it;
	for(int i=9;i>=0;--i)
	{
		cout<<"Level: "<<i<<" ";
		for(it=structure[i].begin();it!=structure[i].end();it++)
		{
			cout<<*it;
		}
		cout<<endl;
	}
	}
	else
	{
		cout<<"Too large to print"<<endl;
	}
}

void Skiplist::insert(int x)
{
	int numOfCompForSpecificValue=0;
	numOfNodes++;
	numofInsertionops++;
	list<Node>::iterator temp;//temp to use for pointing down for new nodes
	list<Node>::iterator linkedlistiterator;//place you are at the list 
	int highestLevelofInsertion = 1+ coinFlip();//determines highest level of insertion
	cout<<"Inserting "<<x<<" up to level: "<<highestLevelofInsertion<<", ";//including the default case of the insertion of the bottom row
	temp = structure[highestLevelofInsertion].end();
	linkedlistiterator = structure[9].begin();
	for(int i=9;i>=0;--i)//fixed for the size of the vector 
	{
		while(x>linkedlistiterator->value)//while the insert value is greater than the current value at iterator
		{
			linkedlistiterator++;//move on to next node
			numofCompForInsertion++;//running total 
			numOfCompForSpecificValue++;//spefic total for specific call
		}
		if(i > highestLevelofInsertion)//move down until you're at the level to start inserting
		{
			linkedlistiterator--;//move back to less than node
			linkedlistiterator = linkedlistiterator->down;//move down
		}
		else
		{
			structure[highestLevelofInsertion].insert(linkedlistiterator,Node(x,temp));//insert the node in list 
			linkedlistiterator--;
			temp->down = linkedlistiterator;
			temp = linkedlistiterator;
			linkedlistiterator--;
			linkedlistiterator = linkedlistiterator->down;
			highestLevelofInsertion--;
		}
	}
	cout<<numOfCompForSpecificValue<<", comparisons"<<
	endl;
}

bool Skiplist::search(int x)
{
	numofSearchops++;
	list<Node>::iterator it = structure[9].begin();
	bool isfound =false;
	for(int i=9;i>=0;i--)
	{
		while(x>it->value)
		{
			it++;
			numofCompForSearch++;//running total of comparisons for entire list
		}
		if(it->value==x)
		{
			isfound =true;
			break;
		}
		else
		{
			it--;
			it= it->down;
		}
	}
	return isfound;
}

void Skiplist::remove(int x)//delete function
{
	numofDeletionops++;
	int numOfCompForSpecificValue_2=0;
	list<Node>::iterator it = structure[9].begin();
	list<Node>::iterator temp;
	for(int i=9;i>=0;i--)
	{
		while(x>it->value)
		{
			it++;
			numofCompForDeletion++;
			numOfCompForSpecificValue_2++;
		}
		if(it->value==x)
		{
			temp = it;
			it--;
			it = it->down;
			structure[i].erase(temp);
		}
		else
		{
			it--;
			it= it->down;
		}
	}
	cout<<"Deleting "<<x<<", "<<numOfCompForSpecificValue_2<<" comparisons"<<endl;
}

void Skiplist::removeAll()//clears everything even the infinity nodes
{
	for(int i=9;i>=0;--i)
	{
	 structure[i].clear();
	}
	numOfNodes=0;
}

double Skiplist::averageDeletionCost()//not counting the deletion of infinty nodes
{
	list<Node>::iterator it=structure[0].begin();
	vector<int> container;
	for(it=++structure[0].begin();it != --structure[0].end();it++)
	{
		container.push_back(it->value);
	}
	for(int i=0; i<container.size()-1;i++)
	{
		this->remove(container[i]);
	}
	return numofCompForDeletion/numofDeletionops;
}
double Skiplist::averageSearchCost()
{
	list<Node>::iterator it = structure[0].begin();
	for(it =++structure[0].begin();it!= --structure[0].end();it++)//starts and ends between the infinity nodes 
	{
		search(it->value);
	}
	return numofCompForSearch/numofSearchops;
}

istream& operator>>(istream& in, Skiplist& sklist)//input operator for skiplist
{
	int value;
	in>>value;
	sklist.insert(value);
}

ostream& operator<<(ostream& out, Node& node) //output operator for a Node
{
	if(node.value == numeric_limits<int>::min())
		{
			out<<"-Inf"<<" ";
		}
		if(node.value == numeric_limits<int>::max())
		{
			out<<"Inf"<<" ";
		}
		if(node.value != numeric_limits<int>::min() && node.value != numeric_limits<int>::max())
		{
			out<<node.value<<" ";
		}
		return out;
}
