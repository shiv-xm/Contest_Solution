#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to compute the number of operations needed to make the array a consecutive sequence
int computeOperations(const vector<int>& segment, int k) {
    unordered_map<int, int> freq;
    int maxConsecutiveLength = 0;

    // Calculate frequencies of each number in the segment
    for (int num : segment) {
        freq[num]++;
    }

    // Collect unique numbers
    vector<int> uniqueNumbers;
    for (const auto& pair : freq) {
        uniqueNumbers.push_back(pair.first);
    }
    sort(uniqueNumbers.begin(), uniqueNumbers.end());

    // Use a sliding window approach to find the longest consecutive subsequence
    int l = 0;
    int currentLength = 0;
    for (int r = 0; r < uniqueNumbers.size(); r++) {
        while (uniqueNumbers[r] - uniqueNumbers[l] >= k) {
            l++;
        }
        currentLength = r - l + 1;
        maxConsecutiveLength = max(maxConsecutiveLength, currentLength);
    }

    return k - maxConsecutiveLength;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; // convert to 0-based index
            r--; // convert to 0-based index

            // Extract the segment of length k
            vector<int> segment(a.begin() + l, a.begin() + l + k);

            // Compute the result for the segment
            int result = computeOperations(segment, k);
            cout << result << endl;
        }
    }

    return 0;
}
