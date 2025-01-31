#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Function to compute the maximum mex value
int computeMaxMex(int x, const vector<vector<int>>& sequences) {
    set<int> present;
    for (const auto& seq : sequences) {
        for (int num : seq) {
            present.insert(num);
        }
    }
    
    while (present.find(x) != present.end()) {
        x++;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> sequences(n);
        for (int i = 0; i < n; ++i) {
            int li;
            cin >> li;
            sequences[i].resize(li);
            for (int j = 0; j < li; ++j) {
                cin >> sequences[i][j];
            }
        }

        // Compute the max mex achievable starting from x = 0
        int maxMex = computeMaxMex(0, sequences);
        long long result = 0;

        // Sum f(0) to f(m) efficiently
        for (int k = 0; k <= m; ++k) {
            result += maxMex;
        }

        cout << result << '\n';
    }

    return 0;
}
