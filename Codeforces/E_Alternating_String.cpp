#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int min_operations_to_make_alternating(const string &s, int n) {
    vector<int> even_count(26, 0);
    vector<int> odd_count(26, 0);

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            even_count[s[i] - 'a']++;
        } else {
            odd_count[s[i] - 'a']++;
        }
    }

    int max_even_count = *max_element(even_count.begin(), even_count.end());
    int max_odd_count = *max_element(odd_count.begin(), odd_count.end());

    return (n / 2 - max_even_count) + (n / 2 - max_odd_count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (n % 2 == 0) {
            // Even length case
            cout << min_operations_to_make_alternating(s, n) << endl;
        } else {
            // Odd length case
            int best = numeric_limits<int>::max();

            vector<int> even_count(26, 0);
            vector<int> odd_count(26, 0);

            for (int i = 0; i < n - 1; ++i) {
                if (i % 2 == 0) {
                    even_count[s[i] - 'a']++;
                } else {
                    odd_count[s[i] - 'a']++;
                }
            }

            for (int i = 0; i < n; ++i) {
                // Adjust frequencies
                if (i % 2 == 0) {
                    even_count[s[i] - 'a']--;
                } else {
                    odd_count[s[i] - 'a']--;
                }

                vector<int> new_even_count = even_count;
                vector<int> new_odd_count = odd_count;

                for (int j = i + 1; j < n; ++j) {
                    if (j % 2 == 0) {
                        new_even_count[s[j] - 'a']++;
                    } else {
                        new_odd_count[s[j] - 'a']++;
                    }
                }

                int max_even_count = *max_element(new_even_count.begin(), new_even_count.end());
                int max_odd_count = *max_element(new_odd_count.begin(), new_odd_count.end());

                best = min(best, (n / 2 - max_even_count) + (n / 2 - max_odd_count) + 1);
            }

            cout << best << endl;
        }
    }

    return 0;
}
