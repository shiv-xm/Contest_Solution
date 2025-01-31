#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimum_possible_score(int n, int k, vector<int>& costs) {
    // Sort costs in ascending order to facilitate optimal distribution of k
    sort(costs.begin(), costs.end());

    // Apply the available k to minimize the difference between the largest and smallest costs
    for (int i = 0; i < n - 1 && k > 0; i++) {
        int diff = costs[n - 1] - costs[i]; // Difference between the largest and current smallest
        int total_increase = min(diff, k);  // How much we can afford to increase costs[i]

        costs[i] += total_increase; // Apply the increase
        k -= total_increase;        // Decrease available k
    }

    // After applying the increases, recalculate the scores for Alice and Bob
    long long A = 0, B = 0;
    for (int i = n - 1; i >= 0; i--) {
        if ((n - i) % 2 == 1) {
            A += costs[i];  // Alice's turn
        } else {
            B += costs[i];  // Bob's turn
        }
    }

    return A - B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> costs(n);
        for (int i = 0; i < n; i++) {
            cin >> costs[i];
        }

        cout << minimum_possible_score(n, k, costs) << endl;
    }

    return 0;
}
