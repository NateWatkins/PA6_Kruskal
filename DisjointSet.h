// File: include/DisjointSet.h
#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <vector>

class DisjointSet {
public:
    // Initialize n disjoint sets (0 through n-1)
    DisjointSet(int n);

    // Find representative of set containing x (with path compression)
    int find(int x);

    // Union sets containing x and y (by rank)
    void unite(int x, int y);

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

#endif // DISJOINTSET_H