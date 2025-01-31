#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w > other.w; // Sort edges by weight in descending order
    }
};

int solve(int n, vector<Edge>& edges, UnionFind& uf, int a, int b, int k) {
    vector<int> path_weights;
    for (const Edge& edge : edges) {
        uf.unite(edge.u, edge.v);
        if (uf.find(a) == uf.find(b)) {
            path_weights.push_back(edge.w);
            if (path_weights.size() == k) {
                break;
            }
        }
    }
    if (path_weights.size() < k) return -1;
    return path_weights[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            --edges[i].u; --edges[i].v;
        }

        // Sort edges by weight in descending order
        sort(edges.begin(), edges.end());

        // Process queries
        while (q--) {
            int a, b, k;
            cin >> a >> b >> k;
            --a; --b;

            UnionFind uf(n);

            // Find the k-th largest edge weight in the path from a to b
            int result = solve(n, edges, uf, a, b, k);
            cout << result << endl;
        }
    }
    return 0;
}
