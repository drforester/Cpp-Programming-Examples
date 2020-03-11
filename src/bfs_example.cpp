
// Print BFS traversal from a given vertex.
#include<iostream> 
#include <list> 
  
using namespace std; 
  
// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
    int N;  // number of vertices 
  
    // Pointer to an array of adjacency lists 
    list<int> *adj;    
public: 
    Graph(int N);  // Constructor 
  
    // add an edge to graph 
    void addEdge(int n, int w);  
  
    // prints BFS traversal from a given source s 
    void BFS(int s);   
};
  
Graph::Graph(int N) { 
    this->N = N; 
    adj = new list<int>[N]; 
} 
  
void Graph::addEdge(int n, int w) { 
    adj[n].push_back(w); // Add w to v’s list. 
} 
  
void Graph::BFS(int s) { 
    // Mark all the vertices as not visited 
    bool *visited = new bool[N]; 
    for(int i = 0; i < N; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 

  
int main() 
{ 
    // Create a graph
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
  
    cout << "Breadth First Traversal (starting from vertex 3) \n"; 
    g.BFS(3); 
  
    return 0; 
} 

