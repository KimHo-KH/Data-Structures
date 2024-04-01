#include "BellmanFord.h"
#include <iostream>

int main() {
    // Create a graph with 5 vertices
    BellmanFord graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 3, -3);
    graph.addEdge(2, 1, 6);
    graph.addEdge(3, 4, 2);

    // Find the shortest paths from source vertex 0
    int source = 0;
    std::pair<bool, std::vector<int>> result = graph.shortestPath(source);

    // Check if a negative cycle was found
    if (result.first) {
        std::cout << "Negative cycle detected in the graph\n";
    } else {
        // Print shortest distances from the source vertex
        std::cout << "Shortest distances from vertex " << source << ":\n";
        for (int i = 0; i < result.second.size(); ++i) {
            std::cout << "Vertex " << i << ": " << result.second[i] << "\n";
        }
    }

    return 0;
}
