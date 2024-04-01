#include "Dijkstra.h"
#include <iostream>

int main() {
    // Create a graph with 5 vertices
    Dijkstra graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 1, 6);
    graph.addEdge(3, 4, 2);

    // Find the shortest paths from source vertex 0
    int source = 0;
    std::vector<int> result = graph.shortestPath(source);

    // Print shortest distances from the source vertex
    std::cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << "Vertex " << i << ": " << result[i] << "\n";
    }

    return 0;
}