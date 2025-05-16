// File: include/WGraph.h
#ifndef WGRAPH_H
#define WGRAPH_H

#include <vector>

// Simple edge representation
struct Edge {
    int u;           // source vertex
    int v;           // destination vertex
    double weight;   // edge weight
};

class WGraph {
public:
    // Construct an empty graph with n vertices
    WGraph(int n);

    // Build graph from an adjacency matrix
    void buildFromMatrix(const std::vector<std::vector<double>>& matrix);

    // Return all edges (u < v) to avoid duplicates
    std::vector<Edge> getEdges() const;

    // Get number of vertices
    int getNumVertices() const;

private:
    int numVertices;
    std::vector<Edge> edges;
};

#endif // WGRAPH_H