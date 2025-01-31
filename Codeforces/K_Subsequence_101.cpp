#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long findMaxF(const vector<int>& A, int K) {
    int N = A.size();
    long long maxF = LLONG_MIN;
    
    // Sliding window sum
    vector<long long> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + A[i - 1];
    }
    
    // Iterate over all possible subsequences of length K
    for (int i = 0; i <= N - K; ++i) {
        long long windowSum = prefixSum[i + K] - prefixSum[i];
        // Calculate f(C) for the current window
        long long currentF = windowSum + A[i] + A[i + K - 1];
        maxF = max(maxF, currentF);
    }

    return maxF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << findMaxF(A, K) << '\n';
    }

    return 0;
}
