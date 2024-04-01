#include "DFS.h"

Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(V);
}

void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
}

void Graph::DFSUtil(int v, std::vector<bool>& visited) {
    visited[v] = true; // Mark the current vertex as visited
    std::cout << v << " "; // Print the current vertex

    // Recur for all the vertices adjacent to this vertex
    for (auto adjVertex : adjList[v]) {
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited);
        }
    }
}

void Graph::DFS(int startVertex) {
    std::vector<bool> visited(V, false); // Mark all vertices as not visited
    DFSUtil(startVertex, visited); // Call the recursive helper function to print DFS traversal
}