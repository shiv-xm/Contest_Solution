#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate XOR sum (a⊕b) + (b⊕c) + (a⊕c)
int calculateXORSum(int a, int b, int c) {
    return (a ^ b) + (b ^ c) + (a ^ c);
}

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int l, r;
        cin >> l >> r;  // Read l and r
        
        // We'll try to consider values that cover the boundary extremes
        vector<int> candidates = {l, r};
        
        // Consider numbers around the edges, like l+1, r-1, l+2, r-2, etc.
        if (l + 1 <= r) candidates.push_back(l + 1);
        if (r - 1 >= l) candidates.push_back(r - 1);
        
        // Sort candidates to ensure we are choosing distinct values
        sort(candidates.begin(), candidates.end());
        
        // We need exactly three distinct values
        int a = candidates[0], b = candidates[1], c = candidates[2];

        // Output the triplet (a, b, c)
        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}
