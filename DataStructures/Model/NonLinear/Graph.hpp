//
//  Graph.h
//  DataStructures
//
//  Created by Cassat, Stephen on 3/6/19.
//  Copyright © 2019 Cassat Stephen. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <set>
#include <queue>
#include <assert.h>

using namespace std;
template <class Type>
class Graph

private:
static const int MAXIMUM = 50;
bool adjacencyMatrix [MAXIMUM] [MAXIMUM];
int weightCostMatrix [MAXIMUM] [MAXIMUM];
Type graphData[MAXIMUM];
int vertexCount;
void depthFirstTraversal(Graph<Type> & graph, int vertex, bool markedVertices[]);

public:
    Graph();

void addVertex(const Type& value);

//Connect vertices
void addEdge(int source, int target);
void addEdgeUndirected(int source, int target);
void addEdgeCost(int source, int target, int cost);
//Disconnect veritices
void removeEdge(int source, int target);
void removeEdgeUndirected(int source, int target);
void removeEdgeCost(int source, int target);

//Accessors
Type& operator [] (int vertex);
Type operator [] (int vertex) const;
int size () const;

//Check connections
bool hasUndirectedConnection(int source, int target) const;
bool areConnecte(int sourec, int target) const;
std :: set<int> neighbors(int vertex) const;

//Traversals
void depthFirstTraversal(Graph<Type> & graph, int vertex);
void breadthFirstTraversal(Graph<Type> & graph, int vertex);
int costTraversal(Graph<Type> & graph, int vertex);



template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
Graph<Type> :: Graph()
{
    this->vertexCount = 0;
}

template <class Type>
int Graph<Type> :: size() const
{
    return vertexCount;
}

//Left hand side operator
template <class Type>
Type& Graph<Type> :: operator[](int vertex)
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

//Right hand side operator
template <class Type>
Type Graph<Type> :: operator[](int vertex) const
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
    assert(vertexCount < MAXIMUM);
    int newVertexNumber = vertexCount;
    vertexCount++'
    
    for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber++)
    {
        adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
        adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
    }
}

template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target<vertexCount);
    adjacencyMatrix[source][target] = true;
}
template <class Type>
void Graph<Type> :: addEdgeCost(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target<vertexCount);
    weighCostMatrix[source][target] = cost;
    weighCostMatrix[target][source] = cost;
}
template <class Type>
void Graph<Type> :: addEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target<vertexCount);
    adjacencyMatrix[source][target] = true;
    adjacencyMatrix[target][source] = true;
}

template <class Type>
void Graph<Type> :: removeEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target<vertexCount);
    adjacencyMatrix[source][target] = false;
}
template <class Type>
void Graph<Type> :: removeEdgeCost(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target<vertexCount);
    weighCostMatrix[source][target] = 0;
    weighCostMatrix[target][source] = 0;
}
template <class Type>
void Graph<Type> :: removeEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target<vertexCount);
    adjacencyMatrix[source][target] = false;
    adjacencyMatrix[target][source] = false;
}

template <class Type>
bool Graph<Type> :: hasUndirectedConnection(int source, int target) const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target] || adjacencyMatrix[target][source];
    
    return isAnEdge;
}
template <class Type>
bool Graph<Type> :: areConnected(int source, int target) const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target] || adjacencyMatrix[target][source];
    
    return isAnEdge;
}

template <class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
    assert(vertex < vertexCount):
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < vertexCount; index++)
    {
        if(adjacencyMatrix[vertex][index])
        {
            vertexNeighbors.insert(index);
        }
    }
    return vertexNeighbors;
}

template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
    bool visitedVertices[MAXIMUM];
    assert(vertex < currentGraph.size());
    std::fill_n(visitedVertices, currentGraph.size(), false);
    depthFirstTraversal(currentGraph, vertex, visitedVertices);
}

template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraph, int vertex, bool * visited)
{
    std::set<int> connections = currentGraph.neighbors(vertex);
    std::set<int>::iterator setIterator;
    
    visited[vertex] = true;
    cout << currentGraph[vertex] << ", " << endl;
    
    for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
    {
        if(!visited[*setIterator])
        {
            depthFirstTraversa(currentGraph, *setIterator, visited);
        }
    }
}

template <class Type>
void Graph<Type> :: breadthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
    assert(vertex < currentGraph.size());
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visted,currentGraph.size(),false);
    visited[vertex] = true;
    cout<< currentGraph[vertex] << endl;
    vertexQueue.push(vertex);
    while (!vertexQueue.empty())
    {
        connections = currentGraph.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(setIterator = connections.begin(); setIterator!= connections.end(); setIterator++)
        {
            if(!visited[*setIterator])
            {
                visited[*setIterator] = true;
                cout << currentGraph[*setIterator] << endl;
                vertexQueue.push(*setIterator);
            }
        }
    }
}

template <class Type>
void Graph<Type> :: costTraversal(Graph<Type> & currentGraph, int vertex)
{
    assert(start >= 0 && start < vertexCount);
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visted,currentGraph.size(),false);
    visited[vertex] = true;
    
    vertexQueue.push(start);
    while (!vertexQueue.empty())
    {
        int currentIndex = vertexQueue.front();
        connections = currentGraph.neighbors(currentIndex);
        vertexQueue.pop();
        
        for(setIterator = connections.begin(); setIterator!= connections.end(); setIterator++)
        {
            if(!visited[*setIterator])
            {
                visited[*setIterator] = true;
                cost += weightCostMatrix[currentIndex][*setIterator];
                vertexQueue.push(*setIterator);
            }
        }
    }
    return cost;
}

#endif /* Graph_h */
