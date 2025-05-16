#include "WGraph.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "DisjointSet.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <matrix_file>\n";
        return 1;
    }

    string filename = argv[1];
    ifstream in(filename);
    if (!in) {
        cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    int n;
    in >> n;
    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> matrix[i][j];
        }
    }
    in.close();

    // Build graph
    WGraph graph(n);
    graph.buildFromMatrix(matrix);
    vector<Edge> edges = graph.getEdges();

    // Kruskal's MST
    DisjointSet ds(n);
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    double totalCost = 0;
    vector<vector<int>> mstAdj(n, vector<int>(n, 0));
    int edgesUsed = 0;
    for (const Edge& e : edges) {
        int u = e.u;
        int v = e.v;
        if (ds.find(u) != ds.find(v)) {
            ds.unite(u, v);
            totalCost += e.weight;
            int w = static_cast<int>(e.weight);
            mstAdj[u][v] = w;
            mstAdj[v][u] = w;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }

    // Print output
    int costInt = static_cast<int>(totalCost);
    cout << "The MST Cost is: " << costInt << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mstAdj[i][j];
            if (j < n - 1) cout << ' ';
        }
        cout << '\n';
    }
return 0;
}