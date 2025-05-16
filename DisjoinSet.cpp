#include "DisjointSet.h"
#include <string>


using namespace std;


// initialize DS: each node is its own parent, rank starts at zero
DisjointSet::DisjointSet(int n)
    : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i)
        parent[i] = i;
}

// find set root, compress path on the way up
int DisjointSet::find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// unite two trees by rank to keep them shallow
void DisjointSet::unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) // already in same set
        return;
    if (rank[rx] < rank[ry])
        parent[rx] = ry;
    else if (rank[ry] < rank[rx])
        parent[ry] = rx;
    else {
        parent[ry] = rx;  // break tie
        rank[rx]++;       // increment tree height
    }
}
