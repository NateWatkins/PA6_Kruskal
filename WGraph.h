// Nathan Watkins
// 2443602
// nwatkins@chapman.edu
// CPSC-350-01
// Assignment PA3
#ifndef WGRAPH_H
#define WGRAPH_H

#include <vector>

using namespace std;


struct Edge {
    int u, v;    // endpoints
    double weight; // edge cost
};

class WGraph {
public:
    // init graph for n vertices
    explicit WGraph(int n);

    // build edge list from full matrix (upper triangle)
    void buildFromMatrix(const vector<vector<double>>& matrix);

    // retrieve edge list
    vector<Edge> getEdges() const;

    // vertex count
    int getNumVertices() const;

private:
    int numVertices;         // node count
    vector<Edge> edges; // collected edges
};

#endif // WGRAPH_H