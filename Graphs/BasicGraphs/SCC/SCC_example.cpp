#include "SCC.h"

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(3, 1);
    graph.addEdge(3, 2);
    graph.addEdge(4, 3);

    std::vector<std::vector<int>> SCCs = graph.findSCC();
    std::cout << "Strongly Connected Components:\n";
    for (const auto& SCC : SCCs) {
        for (int vertex : SCC) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}