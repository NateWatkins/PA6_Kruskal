

// source: build and expose weighted edges
#include "WGraph.h"

WGraph::WGraph(int n) : numVertices(n) {
    edges.clear();  // start fresh
}

void WGraph::buildFromMatrix(const vector<vector<double>>& matrix) {
    edges.clear();  // reset edge list
    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            double w = matrix[i][j];
            if (w > 0) {    // skip misses
                edges.push_back({i, j, w});
            }
        }
    }
}

vector<Edge> WGraph::getEdges() const {
    return edges;  // by value for simplicity
}

int WGraph::getNumVertices() const {
    return numVertices;  // node count
}