#include "BFS.h"

Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(V);
}

void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
}

void Graph::BFS(int startVertex) {
    std::vector<bool> visited(V, false); // Mark all vertices as not visited
    std::queue<int> queue; // Create a queue for BFS

    visited[startVertex] = true; // Mark the current vertex as visited and enqueue it
    queue.push(startVertex);

    while (!queue.empty()) {
        startVertex = queue.front(); // Dequeue a vertex from queue and print it
        std::cout << startVertex << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex startVertex
        // If an adjacent vertex has not been visited, then mark it visited and enqueue it
        for (auto adjVertex : adjList[startVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
}