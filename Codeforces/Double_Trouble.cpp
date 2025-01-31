#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            minHeap.push(x);
        }
        
        // Perform K operations
        for (int i = 0; i < k; ++i) {
            int smallest = minHeap.top();
            minHeap.pop();
            smallest *= 2;
            minHeap.push(smallest);
        }
        
        // Calculate the sum of the array modulo MOD
        long long sum = 0;
        while (!minHeap.empty()) {
            sum += minHeap.top();
            sum %= MOD;
            minHeap.pop();
        }
        
        cout << sum << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
