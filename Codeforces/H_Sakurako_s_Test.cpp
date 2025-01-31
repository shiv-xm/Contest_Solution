#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to handle each test case
void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    
    // Read the array elements
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to make it easier to find the median
    sort(a.begin(), a.end());
    
    // Handle each query
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        
        // Use binary search to find the first element >= x
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        
        // The number of elements >= x is (n - pos)
        int k = n - pos;
        
        // If k >= the number of elements needed to shift the median, print the result
        if (k >= (n + 1) / 2) {
            cout << 1 << " ";  // You can shift the median
        } else {
            cout << 0 << " ";  // You cannot shift the median
        }
    }
    
    // Print a new line after the queries for this test case
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    // Process each test case
    while (t--) {
        solve();
    }
    
    return 0;
}
