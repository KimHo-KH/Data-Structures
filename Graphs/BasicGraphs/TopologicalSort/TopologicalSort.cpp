#include "TopologicalSort.h"

Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(V);
}

void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
}

void Graph::DFSUtil(int v, std::vector<bool>& visited, std::stack<int>& stack) {
    visited[v] = true; // Mark the current vertex as visited

    // Recur for all the vertices adjacent to this vertex
    for (auto adjVertex : adjList[v]) {
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited, stack);
        }
    }

    // Push the current vertex onto the stack
    stack.push(v);
}

std::vector<int> Graph::topologicalSort() {
    std::vector<bool> visited(V, false); // Mark all vertices as not visited
    std::stack<int> stack; // Create a stack to store the topological order

    // Perform DFS traversal on all vertices
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            DFSUtil(i, visited, stack);
        }
    }

    // Create a vector to store the topological order
    std::vector<int> topologicalOrder;
    while (!stack.empty()) {
        topologicalOrder.push_back(stack.top()); // Push vertices from stack to the topological order vector
        stack.pop();
    }

    return topologicalOrder;
}