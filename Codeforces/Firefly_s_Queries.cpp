#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;  // number of test cases
    
    while (t--) {
        int n, q;
        cin >> n >> q;  // length of array and number of queries
        
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];  // input array
        }
        
        // Precompute prefix sums for the array `a`
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i-1] + a[i-1];  // prefix_sum[i] stores sum of a[0] to a[i-1]
        }
        
        // Process each query
        while (q--) {
            long long l, r;
            cin >> l >> r;
            
            // Convert l and r to 0-based indices
            --l;
            --r;
            
            long long total_sum = 0;
            
            // Calculate start and end blocks and indices
            int start_block = l / n;
            int end_block = r / n;
            int start_idx = l % n;
            int end_idx = r % n;
            
            // If both l and r are in the same block, sum the portion directly
            if (start_block == end_block) {
                total_sum = prefix_sum[end_idx + 1] - prefix_sum[start_idx];
            } else {
                // Sum part from start_idx to the end of the first block
                total_sum += prefix_sum[n] - prefix_sum[start_idx];
                // Sum part from the start of the last block to end_idx
                total_sum += prefix_sum[end_idx + 1];
                // Add full blocks in between
                total_sum += (end_block - start_block - 1) * prefix_sum[n];
            }
            
            cout << total_sum << "\n";
        }
    }
    
    return 0;
}
