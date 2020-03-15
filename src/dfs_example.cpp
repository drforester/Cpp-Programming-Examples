/*
Depth-first-search (DFS) from a given vertex in a graph.
*/

#include<iostream> 
#include <list> 

using std::cout;
using std::list; 

class Graph 
{ 
    int N; // number of vertices 
    list<int> *adj; // pointer to array of adjacency lists 
    void DFSrecur(int v, bool visited[]);
public: 
    Graph(int N); // create a Graph with N vertices
    void addEdge(int n, int w); // add an edge between two vertices
    void DFS(int s); // DFS traversal from source vertex s 
};
  
Graph::Graph(int N) { 
    this->N = N; 
    adj = new list<int>[N]; 
} 
  
void Graph::addEdge(int n, int w) { 
    adj[n].push_back(w);
} 

void Graph::DFSrecur(int v, bool visited[]) 
{ 
    // set the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSrecur(*i, visited); 
}
  
// DFS traversal of the vertices reachable from s 
void Graph::DFS(int s) 
{ 
    // set all the vertices as not visited 
    bool *visited = new bool[N]; 
    for (int i = 0; i < N; i++) 
        visited[i] = false; 
  
    // call the recursive helper function  
    DFSrecur(s, visited); 
} 

  
int main() 
{ 
    // create a graph
    Graph g(24);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,0);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(3,6);
    g.addEdge(4,1);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.addEdge(5,2);
    g.addEdge(5,6);
    g.addEdge(6,3);
    g.addEdge(6,5);
    g.addEdge(6,7);
    g.addEdge(7,4);
    g.addEdge(7,6);
    g.addEdge(7,8);
    g.addEdge(8,7);
  
    cout << "Depth First Traversal (starting from vertex 3) \n"; 
    g.DFS(3); 
  
    return 0; 
} 
