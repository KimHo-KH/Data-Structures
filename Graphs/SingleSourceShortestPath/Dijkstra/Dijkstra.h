#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <queue>
#include <utility>
#include <limits>

class Dijkstra {
private:
    int V; // Number of vertices
    std::vector<std::vector<std::pair<int, int>>> adjList; // Adjacency list representation of the graph

public:
    Dijkstra(int vertices);
    void addEdge(int src, int dest, int weight);
    std::vector<int> shortestPath(int source);
};

#endif // DIJKSTRA_H