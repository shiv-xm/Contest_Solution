#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        string s;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cin >> s;

        long long maxScore = 0;

        // Calculate the sum for all valid segments where 'L' is followed by 'R'
        int i = 0;
        while (i < n) {
            if (s[i] == 'L') {
                int l = i;
                // Find the next 'R' to close the segment
                while (i < n && s[i] != 'R') {
                    ++i;
                }
                if (i < n && s[i] == 'R') {
                    // Valid segment found from l to i (inclusive)
                    long long segmentSum = 0;
                    for (int j = l; j <= i; ++j) {
                        segmentSum += a[j];
                    }
                    maxScore += segmentSum;
                    ++i;  // Move past the 'R'
                }
            } else {
                ++i;
            }
        }

        cout << maxScore << endl;
    }

    return 0;
}
