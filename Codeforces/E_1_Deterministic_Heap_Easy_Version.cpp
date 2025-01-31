#include <iostream>
#include <vector>

using namespace std;

// Function to compute nCr % p using precomputed factorial and inverse factorial arrays
long long binomial_coefficient(int n, int r, vector<long long>& fact, vector<long long>& inv_fact, int p) {
    if (r > n || r < 0) return 0;
    return (fact[n] * inv_fact[r] % p) * inv_fact[n - r] % p;
}

// Function to compute factorial and modular inverses of factorials
void precompute_factorials(int max_n, vector<long long>& fact, vector<long long>& inv_fact, int p) {
    fact[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        fact[i] = fact[i - 1] * i % p;
    }
    inv_fact[max_n] = 1;
    for (int i = max_n - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % p;
    }
}

// Function to count the number of deterministic max-heaps
long long count_deterministic_heaps(int n, int k, int p) {
    int total_nodes = (1 << n) - 1;

    vector<long long> fact(total_nodes + 1), inv_fact(total_nodes + 1);
    precompute_factorials(total_nodes, fact, inv_fact, p);

    vector<vector<long long>> dp(total_nodes + 1, vector<long long>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < total_nodes; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (dp[i][j] > 0) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                if (left < total_nodes) {
                    for (int x = 0; x <= k - j; ++x) {
                        long long comb = binomial_coefficient(k - j, x, fact, inv_fact, p);
                        dp[left][j + x] = (dp[left][j + x] + dp[i][j] * comb) % p;
                        dp[right][j + x] = (dp[right][j + x] + dp[i][j] * comb) % p;
                    }
                }
            }
        }
    }

    return dp[0][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        cout << count_deterministic_heaps(n, k, p) << endl;
    }

    return 0;
}