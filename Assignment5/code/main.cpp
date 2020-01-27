#include "skipList.cpp"
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

Skiplist read_file(string file_name)
{
	Skiplist skl;
	ifstream inputFile;
	inputFile.open(file_name);
	while(!inputFile.eof())
	{
		inputFile>>skl;
	}
	return skl;
}

int main()
{
	srand(time(NULL));
	
	//Some tests
	Skiplist skl1;
	cout<<"Just some skip list for tests: \n";
	skl1.insert(2);
	skl1.insert(4);
	skl1.insert(1);
	cout<<"skl1: \n";
	skl1.printSkipList();
	cout<<endl;
	cout<<"Testing remove function:\n";
	skl1.remove(2);
	skl1.printSkipList();
	cout<<endl;
	cout<<"Testing search function:\n";
	cout<<"Is 2 in the skip list?: "<<skl1.search(2);
	cout<<endl;
	cout<<endl;
	//Testing files
	cout<<"Testing file 4l\n";
	Skiplist skl = read_file("4l");
	skl.printSkipList();
	cout<<"Number of Nodes (not including infinities): "<<skl.get_numOfNodes()<<endl;
	cout<<"Average Insertion cost: "<<skl.averageInsertionCost()<<endl;
	cout<<"Average Search cost: "<<skl.averageSearchCost()<<endl;
	cout<<"Average Deletion cost: "<<skl.averageDeletionCost()<<endl;
	
}