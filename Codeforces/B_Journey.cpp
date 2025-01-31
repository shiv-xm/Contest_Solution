#include <iostream>
#include <vector>
#include <tuple> // Include this for std::tuple
using namespace std;

vector<int> monocarpJourney(int t, vector<tuple<int, int, int, int>> test_cases) {
    vector<int> results;

    for (const auto& [n, a, b, c] : test_cases) {
        int S = a + b + c; // Total distance in 3 days
        int full_cycles = n / S; // Full 3-day cycles
        int distance_covered = full_cycles * S;
        int remaining_distance = n - distance_covered;

        if (remaining_distance == 0) {
            results.push_back(full_cycles * 3);
        } else {
            int day = 1;
            for (int daily_distance : {a, b, c}) {
                remaining_distance -= daily_distance;
                if (remaining_distance <= 0) {
                    results.push_back(full_cycles * 3 + day);
                    break;
                }
                day++;
            }
        }
    }

    return results;
}

int main() {
    int t;
    cin >> t;

    vector<tuple<int, int, int, int>> test_cases(t);
    for (int i = 0; i < t; ++i) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        test_cases[i] = {n, a, b, c};
    }

    vector<int> results = monocarpJourney(t, test_cases);

    for (int result : results) {
        cout << result << "\n";
    }

    return 0;
}
