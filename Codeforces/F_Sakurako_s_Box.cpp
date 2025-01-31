#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

// Function to compute power of a number with mod using exponentiation by squaring
long long modPow(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        long long sum = 0, sumSq = 0;
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum = (sum + a[i]) % MOD;
            sumSq = (sumSq + a[i] * a[i]) % MOD;
        }
        
        // Calculate P and Q
        long long P = (sum * sum % MOD - sumSq + MOD) % MOD;
        long long Q = (n * (n - 1)) % MOD;
        
        // Ensure Q is not zero (it should not be in valid cases)
        if (Q == 0) {
            cout << "Error: Q is zero" << endl;
            continue;
        }
        
        // Find Q inverse using Fermat's Little Theorem
        long long Q_inv = modPow(Q, MOD - 2, MOD);
        
        // Output the result P * Q^-1 % MOD
        cout << (P * Q_inv % MOD) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    return 0;
}
