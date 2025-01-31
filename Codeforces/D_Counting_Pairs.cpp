#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countInterestingPairs(int t, vector<tuple<int, int, int, vector<int>>> test_cases) {
    vector<int> results;

    for (const auto& test_case : test_cases) {
        int n = get<0>(test_case);
        long long x = get<1>(test_case), y = get<2>(test_case);
        vector<int> a = get<3>(test_case);

        sort(a.begin(), a.end());
        int count = 0;

        // Iterate over each element as the first element of the pair
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long remaining_sum = accumulate(a.begin(), a.end(), 0LL) - a[i] - a[j];
                if (remaining_sum >= x && remaining_sum <= y) {
                    count++;
                }
            }
        }

        results.push_back(count);
    }

    return results;
}

int main() {
    int t;
    cin >> t;

    vector<tuple<int, int, int, vector<int>>> test_cases(t);
    for (int i = 0; i < t; ++i) {
        int n;
        long long x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }

        test_cases[i] = {n, x, y, a};
    }

    vector<int> results = countInterestingPairs(t, test_cases);

    for (int res : results) {
        cout << res << "\n";
    }

    return 0;
}
