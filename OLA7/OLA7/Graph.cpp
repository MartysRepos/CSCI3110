//Martavious Dorsey
//Due Date: 11-28-16
//Description: I designed and implemented a connected, undirected, weighted graph.
#include "Graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


// Add a vertex
// precond: node never appear in the graph before
void Graph::addVertex(const std::string & node)
{
	auto finder = the_Graph.find(node);
	if (finder == the_Graph.end())
	{
		the_Graph[node];
	}
	else
	{
		cout << "node is already in the List" << endl;
	}

}

// Add an edge.
// Throw a GraphException if vertices of this
// node are not in this graph
// pre-cond: the edge between sourceName and targetName does not exist
void Graph::addEdge(std::string sourceName, std::string targetName, int weight) throw(GraphException)
{
	if (the_Graph.find(sourceName) != the_Graph.end() && the_Graph[sourceName].find(targetName) != the_Graph[sourceName].end())
	{
		cout << "Graph already contains this edge" << endl;
	}
	else
	{
		the_Graph[sourceName][targetName] = weight;
		the_Graph[targetName][sourceName] = weight;
	}
}

// Remove a vertex and related arcs
// Throw a GraphException if such vertex does not exist
void Graph::removeVertex(std::string nodeName) throw(GraphException)
{
	the_Graph.erase(nodeName);
	for (auto it : the_Graph)
	{
		the_Graph[it.first].erase(nodeName);
	}
}


// Remove an edge 
// Throw a GraphException if both vertices are not in the graph
// Do nothing if the edge does not exist
void Graph::removeEdge(std::string srcName, std::string destName) throw(GraphException)
{
	if (the_Graph.find(srcName) != the_Graph.end() && the_Graph[srcName].find(destName) != the_Graph[srcName].end())
	{
		cout << "Graph already contains this edge" << endl;
	}
	else
	{
		the_Graph[srcName].erase(destName);
		the_Graph[destName].erase(srcName);
	}
}


// Depth-first traversal: visit ALL vertices once
// During the visit, print edges in the order they are visited
// If graph has no edge, print some information
void Graph::DFS(const std::string & source)
{
	map <string, bool> visted;
	auto finder = the_Graph.find(source);
	if (finder == the_Graph.end())
	{
		cout << "Node is not in graph, so there is no edge to that graph" << endl;
	}

	visted[source] = true;

	for (auto it : the_Graph[source])
	{
		if (visted.find(it.first) == visted.end())//if not visited
		{
			cout << "(" << source << ", " << it.first << ") ";
			DFS(it.first);
		}
	}

	cout << "->";
}

// Breadth-first traversal: visit ALL vertices once
// During the visit, print edges in the order they are visited
// If graph has no edge, print some information
void Graph::BFS(const std::string & source)
{
	map <string, bool> visted; //used to save if the node has already been visited
	queue<string> bfsQueue; //saves every visited node

							//puts the node into the queue and markes it as already visted
	bfsQueue.push(source);
	visted[source] = true;

	//Begins the actual BFS
	while (!bfsQueue.empty())
	{
		/** Pop the vertex from the queue */
		string current = bfsQueue.front();
		bfsQueue.pop();

		//Looks to see all the neighboring nodes to the source node.
		for (auto it : the_Graph[current])
		{
			//if not visited enqueue
			if (visted.find(it.first) == visted.end())
			{
				cout << current << ", " << it.first;

				bfsQueue.push(it.first);
				visted[it.first] = true;
			}

		}
	}
	cout << endl;

}

// Find shortest path from the node "source"
void Graph::shortestPath(const std::string & source)
{

}

// print the graph
std::ostream & operator<<(std::ostream & os, const Graph & rhs)
{
	os << string(25, '*') << "Graph" << string(25, '*') << endl;
	os << "Vertices:\n";
	for (auto it : rhs.the_Graph)
	{
		os << it.first << "\t";
	}
	os << "\n\nEdges:\n";
	for (auto it : rhs.the_Graph)
	{
		for (auto x : it.second)
		{
			os << "( " << it.first << ", " << x.first << ", " << x.second << " )\t";
		}
	}

	return os;
}


	
