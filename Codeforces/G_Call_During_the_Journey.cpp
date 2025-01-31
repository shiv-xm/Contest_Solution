#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX;

// Structure to represent edges with bus and walk times
struct Edge {
    int to;
    long long busTime;
    long long walkTime;
};

// Function to perform Dijkstra's algorithm to find shortest paths
void dijkstra(int start, vector<vector<Edge>>& graph, vector<long long>& dist, bool useBus) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            long long weight = useBus ? edge.busTime : edge.walkTime;
            if (dist[u] + weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        long long t0, t1, t2;
        cin >> t0 >> t1 >> t2;
        
        vector<vector<Edge>> graph(n + 1);
        vector<long long> busDist(n + 1, INF);
        vector<long long> walkDist(n + 1, INF);
        
        for (int i = 0; i < m; ++i) {
            int u, v;
            long long l1, l2;
            cin >> u >> v >> l1 >> l2;
            
            graph[u].push_back({v, l1, l2});
            graph[v].push_back({u, l1, l2});
        }
        
        // Find shortest paths using bus travel
        dijkstra(1, graph, busDist, true);
        
        // Find shortest paths using walking
        dijkstra(1, graph, walkDist, false);
        
        long long maxDepartureTime = -1;
        
        for (int i = 1; i <= n; ++i) {
            long long timeWithBus = busDist[i];
            long long timeWithWalk = walkDist[i];
            
            if (timeWithBus <= t1) {
                long long latestDeparture = t0 - max(t1 + timeWithWalk, t2 + timeWithBus);
                if (latestDeparture >= 0) {
                    maxDepartureTime = max(maxDepartureTime, latestDeparture);
                }
            }
        }
        
        cout << maxDepartureTime << endl;
    }
    
    return 0;
}
