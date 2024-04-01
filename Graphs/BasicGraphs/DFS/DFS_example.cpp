#include "DFS.h"

int main() {
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    std::cout << "Depth First Traversal starting from vertex 2: ";
    graph.DFS(2);
    std::cout << std::endl;

    return 0;
}