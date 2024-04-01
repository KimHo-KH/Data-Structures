#ifndef DFS_H
#define DFS_H

#include <vector>
#include <iostream>

class Graph {
private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjList; // Adjacency list representation of the graph

    // Recursive function to perform DFS traversal
    void DFSUtil(int v, std::vector<bool>& visited);

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void DFS(int startVertex);
};

#endif // DFS_H