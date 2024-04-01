#include "SCC.h"

Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(V);
    adjListTranspose.resize(V);
}

void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
    adjListTranspose[dest].push_back(src); // Transpose of the adjacency list
}

void Graph::DFSVector(int v, std::vector<bool>& visited, std::vector<int>& component) {
    visited[v] = true; // Mark the current vertex as visited
    component.push_back(v); // Add the current vertex to the current SCC

    // Recur for all the vertices adjacent to this vertex
    for (auto adjVertex : adjListTranspose[v]) {
        if (!visited[adjVertex]) {
            DFSVector(adjVertex, visited, component);
        }
    }
}

void Graph::DFSStack(int v, std::vector<bool>& visited, std::stack<int>& component) {
    visited[v] = true; // Mark the current vertex as visited
    component.push(v); // Add the current vertex to the current SCC

    // Recur for all the vertices adjacent to this vertex
    for (auto adjVertex : adjListTranspose[v]) {
        if (!visited[adjVertex]) {
            DFSStack(adjVertex, visited, component); // Recur with the same component stack
        }
    }
}

std::vector<std::vector<int>> Graph::findSCC() {
    std::vector<bool> visited(V, false); // Mark all vertices as not visited
    std::stack<int> stack; // Create a stack to store the order of finishing times during the first DFS
    std::vector<std::vector<int>> SCCs; // Vector to store the Strongly Connected Components

    // Perform DFS traversal on all vertices to fill the stack
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            DFSStack(i, visited, stack); // Use DFSStack to fill the stack
        }
    }

    // Mark all vertices as not visited for the second DFS
    visited.assign(V, false);

    // Perform DFS traversal on the transpose of the graph and find SCCs
    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (!visited[v]) {
            std::vector<int> component;
            DFSVector(v, visited, component); // Use DFSVector for second DFS traversal
            SCCs.push_back(component);
        }
    }

    return SCCs;
}
