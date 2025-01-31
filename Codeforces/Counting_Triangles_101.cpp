#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// Precompute factorials and modular inverses
vector<long long> factorial;
vector<long long> inv_factorial;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precompute_factorials(int max_n) {
    factorial.resize(max_n + 1);
    inv_factorial.resize(max_n + 1);
    
    factorial[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    
    inv_factorial[max_n] = mod_exp(factorial[max_n], MOD - 2, MOD);
    for (int i = max_n - 1; i >= 0; --i) {
        inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % MOD;
    }
}

long long comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return factorial[n] * inv_factorial[k] % MOD * inv_factorial[n - k] % MOD;
}

long long count_good_sets(int N, int M) {
    
    return comb(M, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    // Precompute factorials up to the maximum constraint
    precompute_factorials(1000000); // Max M for constraints
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        cout << count_good_sets(N, M) << '\n';
    }
    
    return 0;
}
