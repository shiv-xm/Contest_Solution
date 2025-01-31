#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int MAXN = 500000 + 5;
const int INF = numeric_limits<int>::max();

vector<int> A(MAXN);
vector<int> dist(MAXN);

void multi_source_bfs(int N) {
    fill(dist.begin(), dist.begin() + N + 1, INF);
    queue<int> q;

    // Initialize the queue with all nodes that have outgoing edges
    for (int i = 1; i <= N; ++i) {
        if (A[i] > 0) {
            q.push(i);
            dist[i] = 0;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int j = 1; j <= A[node] && node + j <= N; ++j) {
            int next_node = node + j;
            if (dist[next_node] == INF) { // Not visited
                dist[next_node] = dist[node] + 1;
                q.push(next_node);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, Q;
        cin >> N >> Q;

        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
        }

        multi_source_bfs(N);  // Precompute shortest paths from all sources

        while (Q--) {
            int X, Y;
            cin >> X >> Y;
            if (X > N || Y > N || dist[X] == INF) {
                cout << -1 << '\n';
            } else {
                cout << dist[Y] << '\n';
            }
        }
    }

    return 0;
}
