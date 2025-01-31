#include <bits/stdc++.h>
#include <vector>
#include <numeric> // For std::gcd
using namespace std;

// Function to compute LCM of two numbers
int lcm(int a, int b) {
    return (a / std::gcd(a, b)) * b; // Use std::gcd
}

int main() {
    int t;
    cin >> t; // Number of test cases
    vector<int> results;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        results.push_back(lcm(a, b)); // Compute LCM and store it
    }
    
    // Output all results
    for (int res : results) {
        cout << res << endl;
    }
    
    return 0;
}
