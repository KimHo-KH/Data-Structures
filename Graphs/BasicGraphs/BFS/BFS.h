#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <iostream>

class Graph {
private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adjList; // Adjacency list representation of the graph

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

#endif // BFS_H