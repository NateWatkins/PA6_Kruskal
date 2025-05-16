#include "WGraph.h"
#include <vector>

using namespace std;


WGraph::WGraph(int n) : numVertices(n){
    edges.clear();
}

void WGraph::buildFromMatrix(const vector<vector<double>>& matrix) {
    edges.clear();
    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            double w = matrix[i][j];
            if (w > 0) {
                Edge e;
                e.u = i;
                e.v = j;
                e.weight = w;
                edges.push_back(e);
            }
        }
    }
}

vector<Edge> WGraph::getEdges() const {
    return edges;
}

int WGraph::getNumVertices() const {
    return numVertices;
}
