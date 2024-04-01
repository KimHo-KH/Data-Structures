#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include <vector>
#include <limits>

class BellmanFord {
private:
    int V; // Number of vertices
    std::vector<std::vector<std::pair<int, int>>> edges; // Graph representation (can be adjacency list, etc.)

public:
    BellmanFord(int vertices);
    void addEdge(int src, int dest, int weight);
    std::pair<bool, std::vector<int>> shortestPath(int source);
};

#endif // BELLMAN_FORD_H
