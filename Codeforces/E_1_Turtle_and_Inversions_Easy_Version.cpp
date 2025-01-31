#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate maximum inversions in a permutation of length n
long long maxInversions(int n) {
    return (long long)n * (n - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> intervals(m);
        for (int i = 0; i < m; ++i) {
            cin >> intervals[i].first >> intervals[i].second;
        }

        // Sort intervals by their end points
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        bool isPossible = true;
        int last_end = 0;

        for (const auto& interval : intervals) {
            if (interval.first <= last_end) {
                isPossible = false;
                break;
            }
            last_end = interval.second;
        }

        if (isPossible) {
            cout << maxInversions(n) << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
