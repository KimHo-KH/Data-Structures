#include "TopologicalSort.h"
#include <iostream>

int main() {
    Graph graph(6);

    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    std::cout << "Topological sorting order: ";
    std::vector<int> order = graph.topologicalSort();
    for (int vertex : order) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}