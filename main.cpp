#include "WGraph.h"
#include <vector>
#include <iostream>
#include <string>
#include "DisjointSet.h"

using namespace std;




int main() {
    // Example adjacency matrix for 4 vertices
    std::vector<std::vector<double>> matrix = {
        {0, 1.5, 0, 2.0},
        {1.5, 0, 3.2, 0},
        {0, 3.2, 0, 4.1},
        {2.0, 0, 4.1, 0}
    };

    int n = matrix.size();
    WGraph graph(n);
    graph.buildFromMatrix(matrix);

    std::cout << "Graph has " << graph.getNumVertices() << " vertices and "
              << graph.getEdges().size() << " edges:\n";
    for (const Edge& e : graph.getEdges()) {
        std::cout << e.u << " -- " << e.v << " (" << e.weight << ")\n";
    }

    // Test DisjointSet
    DisjointSet ds(n);
    ds.unite(0, 1);
    ds.unite(1, 2);
    std::cout << "Representative of 2: " << ds.find(2) << "\n";
    std::cout << "Representative of 3 (alone): " << ds.find(3) << "\n";

    return 0;
}