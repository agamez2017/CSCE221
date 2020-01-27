#include "drawGraph.cpp"
#include <iostream>
#include <fstream>
/*
	Main File 
	Name: Adrian Gamez-Rodriguez
	username: adriangamez
	section: 517
	email adress: adriangamez@tamu.edu
*/
using namespace std;

Graph read_file(string file_name)
{
	Graph g1;
	ifstream inputFile;
	inputFile.open(file_name);
	inputFile>>g1;
	return g1;
}
int main(int argc, char* argv[])
{
	if(argc==1)
	{
		cout<<"No file argument\n";
	}
	if(argc>=3)
	{
		cout<<"Too many files\n";
	}
	else if(argc==2)
	{
	string file_name = argv[1];
	cout<<"Data file entered: "<<file_name<<endl;
	Graph g1;
	g1 = read_file(file_name);
	cout<<"Corresponding output: "<<endl;
	cout<<g1<<endl;
	cout<<"Can this graph be drawn in one stroke? (0= no, 1= yes): "<<g1.canBeDrawnInOneStroke()<<endl;
	cout<<"Number of Odd Vertices: "<<g1.get_numOfOddVertices()<<endl;
	cout<<"Number of Even Vertices: "<<g1.get_numOfEvenVertices()<<endl;
	if(g1.canBeDrawnInOneStroke())
	{
		cout<<"Starting Vertex : "<<g1.findStartingVertex();
		int start = g1.findStartingVertex();
		cout<<endl;
		cout<<"Path: \n";
		g1.printPath(start);
	}
	else
	{
		cout<<"No path found.\n";
	}
	}
	return 0;
}