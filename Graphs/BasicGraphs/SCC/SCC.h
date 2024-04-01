#ifndef SCC_H
#define SCC_H

#include <vector>
#include <stack>
#include <iostream>

class Graph {
private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjList; // Adjacency list representation of the graph
    std::vector<std::vector<int>> adjListTranspose; // Transpose of the adjacency list

    // Recursive function to perform DFS traversal
    void DFSVector(int v, std::vector<bool>& visited, std::vector<int>& component);
    void DFSStack(int v, std::vector<bool>& visited, std::stack<int>& component); 

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    std::vector<std::vector<int>> findSCC();
};

#endif // SCC_H
