/******************************************************************************
Graph:
1. A finite set of vertices also called nodes
2. A finite set of ordered pairs (u,v) called as edge. The pais is ordered
   because (u,v) is not the same as (v,u) in case of a directed graph. The pair
   of the form (u,v) indicares that there is an edge from vertex u to vertex v.
   The edges may contain weight/value/cost.
   
Most common representations of graphs:
1. Adjacency Matrix
2. Adjacency List
*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for(int v = 0; v<V; ++v){
        cout << "Adjacency List for " << v << "\nhead";
        for(auto x: adj[v])
        {
            cout << "->" << x;
        }
        printf("\n");
    }
}

int main() 
{ 
    int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, V); 
    return 0; 
} 
