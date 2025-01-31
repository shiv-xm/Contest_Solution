#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n + 1);  // permutation array
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        string s;
        cin >> s;
        s = ' ' + s;  // 1-based indexing for string s

        vector<int> visited(n + 1, 0);  // To track visited elements
        vector<int> result(n + 1, 0);   // To store F(i) for each i

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                // Find the cycle starting from i
                vector<int> cycle;
                int current = i;

                // Traverse the cycle
                while (!visited[current]) {
                    visited[current] = 1;
                    cycle.push_back(current);
                    current = p[current];
                }

                // Count black elements in the cycle
                int black_count = 0;
                for (int idx : cycle) {
                    if (s[idx] == '0') {
                        black_count++;
                    }
                }

                // Assign the result for each element in the cycle
                for (int idx : cycle) {
                    result[idx] = black_count;
                }
            }
        }

        // Output the result for the current test case
        for (int i = 1; i <= n; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
