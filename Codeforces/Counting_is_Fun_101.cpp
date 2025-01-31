#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

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

long long count_permutations(const vector<int>& A) {
    unordered_map<int, int> count_map;
    for (int num : A) {
        count_map[num]++;
    }

    long long result = 1;
    for (const auto& entry : count_map) {
        int count = entry.second;
        long long factorial = 1;
        for (int i = 2; i <= count; ++i) {
            factorial = (factorial * i) % MOD;
        }
        result = (result * factorial) % MOD;
    }

    result = (result * result) % MOD;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        cout << count_permutations(A) << '\n';
    }

    return 0;
}
