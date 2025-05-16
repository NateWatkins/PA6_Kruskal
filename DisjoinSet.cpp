#include "DisjointSet.h"

DisjointSet::DisjointSet(int n)
    : parent(n), rank(n, 0)
{
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

int DisjointSet::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void DisjointSet::unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (rank[rx] < rank[ry]) {
        parent[rx] = ry;
    } else if (rank[rx] > rank[ry]) {
        parent[ry] = rx;
    } else {
        parent[ry] = rx;
        rank[rx]++;
    }
}
