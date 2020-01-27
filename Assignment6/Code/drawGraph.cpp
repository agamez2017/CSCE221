/*
	CPP function definiton File 
	Name: Adrian Gamez-Rodriguez
	username: adriangamez
	section: 517
	email adress: adriangamez@tamu.edu
*/
#include "drawGraph.h"
istream& operator>>(istream& in, Graph& graph)
{
	int setnumOfNodes=0;
	int setnumOfEdges=0;
	in>>setnumOfNodes;
	in>>setnumOfEdges;
	graph.set_numOfNodes(setnumOfNodes);
	graph.set_numOfEdges(setnumOfEdges);
	vector<list<int>> temp_2(setnumOfNodes);//for adjacency list
	vector<pair<int, int>> edge;
	for(int i=0;i<setnumOfEdges;i++)
	{
		int index;
		int num;
		in>>index;
		in>>num;
		pair <int, int> pair1 (index,num);
		edge.push_back(pair1);
		temp_2[index-1].push_back(num);
		temp_2[num-1].push_back(index);
	}
	for(int i=0;i<setnumOfNodes;i++)
	{
		temp_2[i].sort();
	}
	in.seekg(0,ios::beg);//go back to the beginning
	in.ignore(1000,'\n');//ignore first line 
	vector<int> col(setnumOfNodes);
	vector<vector<int>> temp(setnumOfNodes, col);//for adjencency matrix
	for(int i=0;i<setnumOfEdges;i++)
	{
		int row;
		int col;
		in>>row;	
		in>>col;
		temp[row-1][col-1]++;
		temp[col-1][row-1]++;
	}
	graph.set_adjList(temp_2);//set the adjacency list
	graph.set_adjMatrix(temp);//set the adjacency matrix
	graph.set_edges(edge);//set the edges (just a vector of pairs)
}

ostream& operator<<(ostream& out, Graph& graph)//output operator
{
	out<<"AdjMatrix:\n";//print out the matrix
	for(int i=0;i<graph.get_adjMatrix().size();i++)
	{
		for(int j=0;j<graph.get_adjMatrix().size();j++)
		{
			cout<<graph.get_adjMatrix()[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"AdjList:\n";//print out the adjencency lists
	for(int i=0;i<graph.get_adjList().size();i++)
	{
		out<<i+1;
		list<int>::iterator it;
		vector<list<int>> temp;
		temp = graph.get_adjList();
		for(it = temp[i].begin(); it!=temp[i].end();it++)
		{
			if(it == --graph.get_adjList()[i-1].end())
			{
				out<<*it;
			}
			else if( it != --graph.get_adjList()[i-1].end())
			{
				out<<" -> "<<*it;
			}
		}
		out<<endl;
	}
	cout<<endl;
	cout<<"Edges:\n";//print out the edges
	for(int i=0;i<graph.get_edges().size();i++)
	{
	out<<"("<<graph.get_edges()[i].first<<","<<graph.get_edges()[i].second<<")";
	}
	return out;
}

bool Graph::canBeDrawnInOneStroke()
{
	//if there are more than two odd vertices its not possible to draw in one stroke
	//if there are 0 odd vertices, meaning all even then it is (start and end anywhere you like)
	//if there are exactly two odd vertices you have to start and end at those vertices
	bool canbe;
	int temp=0;
	int temp_2=0;
	for(int i=0;i<numOfNodes;i++)
	{
		if((adjList[i].size()% 2) == 1)
		{
			temp++;
		}
		if((adjList[i].size() % 2) ==0)
		{
			temp_2++;
		}
	}
	numOfOddVertices = temp;
	numOfEvenVertices = temp_2;
	if(numOfOddVertices >2 || numOfOddVertices ==1)
	{
		canbe = false;
	}
	if(numOfOddVertices ==2 || numOfOddVertices ==0)
	{
		canbe = true;
	} 
	return canbe;
}

int Graph::findStartingVertex()//find the starting vertex
{
	vector<int> indices;
	if(canBeDrawnInOneStroke() && numOfOddVertices ==2)
	{
		for(int i=0;i<numOfNodes;i++)
		{
			if(adjList[i].size() % 2 == 1)
			{
				indices.push_back(i);
			}
		}
		startingVertex = indices[0]+1;
		return startingVertex;
	}
	else if(numOfOddVertices ==0)//meaning all even vertices so start at 1
	{
		startingVertex = 1;
		return startingVertex;
	}
	else
	{
		cout<<"Cannot be drawn in one stroke.\n";
		return -1;
	}
}
void Graph::removeEdge(int u, int v)//removing an edge means replacing all the lists with zeros
{
	list<int>::iterator it = find(adjList[u-1].begin(),adjList[u-1].end(),v);
	*it = 0;//replace with zero meaning it will not be used 
	list<int>::iterator ip = find(adjList[v-1].begin(),adjList[v-1].end(),u);
	*ip = 0;
}
void Graph::addEdge(int u, int v)//add edge to the graph
{
	adjList[u-1].push_back(v);
	adjList[v-1].push_back(u);
}
void Graph::printPath(int start)//start is the starting vertex
{
	list<int>::iterator it;
	for(it = adjList[start-1].begin();it != adjList[start-1].end();it++)//go to corresponding list, and iterate for all adjacent vertices
	{
		int temp = *it;//the adjacent vertex
		if(temp!= 0 && validEdge(start,temp))//if the adjacent vertex is not empty and is valid 
		{
		cout<<"("<<start<<", "<<temp<<") ";
		removeEdge(start, temp);//remove the edge from graph
		printPath(temp);//recursive call to adjacent vertices
		}
	}
}
bool Graph::validEdge(int u, int v)//checks if the edge should be traversed and back tracks if not
{
	int count =0;
	for(list<int>::iterator i= adjList[u-1].begin();i!=adjList[u-1].end();i++)
	{
		if(*i != 0)
		{
			count++;
		}
	}
	if(count == 1)//if there is only 1 available vertex then just consider it 
	{
		return true;
	}
	bool visited[numOfNodes];//array to keep track of visited vertices
	for(int i=0; i<numOfNodes;i++)//set all vertices to unvisited
	{
		visited[i] =false;
	}
	int count1 = reachability(u, visited);//check to see if you can reach remaining vertices from current vertex
	removeEdge(u, v); //remove edge so you don't consider it again
	for(int i=0; i<numOfNodes;i++)//reset all vertices to unvisted
	{
		visited[i] =false;
	}
	int count2 = reachability(u, visited);//now count again the number of reachable vertices since the edge was removed
	addEdge(u, v);//add the edge back 
	return (count1 > count2)? false: true; 
}
int Graph::reachability(int v, bool visited[])//recursive function, DFS based to count reachable vertices from v
{
	visited[v-1] = true;//mark as visited
	int count=1;//count the vertices
	for(list<int>::iterator it = adjList[v-1].begin();it!=adjList[v-1].end();++it)
	{
		if(*it != 0 && !visited[*it-1])
		{
			count += reachability(*it, visited);//call recursively for adjacent nodes
		}
	}
	return count;
}
