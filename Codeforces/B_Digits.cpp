#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int t;
    cin >> t;  // Read number of test cases

    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<int> divisors;

        // 1 is always a divisor
        divisors.push_back(1);

        // Check divisibility by 3
        if (n >= 3) {
            divisors.push_back(3);
        }

        // Check divisibility by 5
        if (d == 5) {
            divisors.push_back(5);
        }

        // Check divisibility by 7
        if (n >= 7) {
            divisors.push_back(7);
        }

        // Check divisibility by 9
        if (n >= 9) {
            divisors.push_back(9);
        }

        // Output the divisors in ascending order
        for (int i = 0; i < divisors.size(); i++) {
            cout << divisors[i] << (i == divisors.size() - 1 ? "\n" : " ");
        }
    }
}

int main() {
    solve();
    return 0;
}
