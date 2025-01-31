#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to calculate the GCD
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long l, r, G;
        cin >> l >> r >> G;
        
        // Find the smallest multiple of G >= l
        long long A = ((l + G - 1) / G) * G;  // A is the smallest multiple of G >= l
        // Find the largest multiple of G <= r
        long long B = (r / G) * G;  // B is the largest multiple of G <= r
        
        // If A > B, it means no multiples of G lie in the range [l, r]
        if (A > B) {
            cout << "-1 -1" << endl;
        } else {
            // If A and B are different, check GCD condition
            if (gcd(A, B) == G) {
                cout << A << " " << B << endl;
            } else {
                // If GCD condition is not satisfied
                cout << "-1 -1" << endl;
            }
        }
    }
    
    return 0;
}
