#include "Dijkstra.h"

Dijkstra::Dijkstra(int vertices) : V(vertices) {
    adjList.resize(V);
}

void Dijkstra::addEdge(int src, int dest, int weight) {
    adjList[src].push_back({dest, weight});
    // For undirected graph, uncomment the line below
    // adjList[dest].push_back({src, weight});
}

std::vector<int> Dijkstra::shortestPath(int source) {
    std::vector<int> distance(V, std::numeric_limits<int>::max());
    distance[source] = 0;

    // Priority queue to store vertices and their distances
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Visit each neighbor of u
        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}