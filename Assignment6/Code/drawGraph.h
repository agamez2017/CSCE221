/*
	Header File 
	Name: Adrian Gamez-Rodriguez
	username: adriangamez
	section: 517
	email adress: adriangamez@tamu.edu
*/

#ifndef DRAWGRAPH_H
#define DRAWGRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <utility>	
#include <algorithm>

using namespace std;
class Graph
{
	private:
	vector<pair<int,int>> edges;
	int numOfOddVertices=0;
	int numOfEvenVertices=0;
	int numOfNodes=0;
	int numOfEdges=0;
	int startingVertex;
	vector<list<int>> adjList;
	vector<vector<int>> adjMatrix;
	
	public:
	Graph(){}
	//functions
	bool canBeDrawnInOneStroke();
	int findStartingVertex();	
	void printPath(int start);
	bool validEdge(int u,int v);
	void removeEdge(int u, int v);
	void addEdge(int u, int v);
	int reachability(int v, bool visit[]);
	
	//getters and setters
	void set_edges(vector<pair<int, int>> x) {edges = x;}
	vector<pair<int, int>> get_edges() const {return edges;}
	int get_numOfOddVertices() const {return numOfOddVertices;}
	int get_numOfEvenVertices() const {return numOfEvenVertices;}
	void set_numOfNodes(int x) {numOfNodes = x;}
	int get_numOfNodes() const {return numOfNodes;}
	void set_numOfEdges(int x) {numOfEdges = x;}
	int get_numOfEdges() const {return numOfEdges;}
	void set_adjList(vector<list<int>> temp_2) {adjList = temp_2;}
	void set_adjMatrix(vector<vector<int>> temp) {adjMatrix = temp;}
	vector<vector<int>> get_adjMatrix() const {return adjMatrix;}
	vector<list<int>> get_adjList() const {return adjList;}
};

ostream& operator<<(ostream& out, Graph& graph);
istream& operator>>(istream& in, Graph& graph);
#endif