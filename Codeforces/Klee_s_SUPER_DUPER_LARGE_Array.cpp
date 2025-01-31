#include <iostream>
using namespace std;

long long min_x(long long n) {
    // Determine the minimum value of x based on whether n is even or odd
    if (n % 2 == 0) {
        return 0;  // For even n, the minimum x can be 0
    } else {
        return n / 2;  // For odd n, the minimum x is n // 2
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;  // Read number of test cases
    
    while (t--) {
        long long n, k;
        cin >> n >> k;  // Read n and k for each test case
        
        cout << min_x(n) << endl;  // Output the minimum value of x
    }

    return 0;
}
