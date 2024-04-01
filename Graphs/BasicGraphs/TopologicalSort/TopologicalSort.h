#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include <vector>
#include <stack>

class Graph {
private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjList; // Adjacency list representation of the graph

    // Recursive function to perform DFS traversal
    void DFSUtil(int v, std::vector<bool>& visited, std::stack<int>& stack);

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    std::vector<int> topologicalSort();
};

#endif // TOPOLOGICALSORT_H