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

BellmanFord::BellmanFord(int vertices) : V(vertices) {
    edges.resize(V);
}

void BellmanFord::addEdge(int src, int dest, int weight) {
    edges[src].push_back({dest, weight});
    // Add other edge handling code as needed
}

std::pair<bool, std::vector<int>> BellmanFord::shortestPath(int source) {
    std::vector<int> distance(V, std::numeric_limits<int>::max());
    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (const auto& edge : edges[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < V; ++u) {
        for (const auto& edge : edges[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                // Negative cycle detected
                // Handle negative cycle if needed
                return {true, std::vector<int>()}; // Indicate negative cycle found
            }
        }
    }

    return {false, distance}; // Indicate no negative cycle found
}
