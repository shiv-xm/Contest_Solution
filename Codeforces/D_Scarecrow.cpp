#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if the crow can reach or exceed position 'l' in the given time
bool canReachWithTime(int n, int k, int l, const vector<int>& scarecrows, int time) {
    int position = 0;  // Starting position of the crow
    for (int i = 0; i < n; ++i) {
        // The maximum position this scarecrow can move to in the given time
        int max_position = scarecrows[i] + time;
        
        // If the crow is too close to this scarecrow, teleport
        if (position + k > max_position) {
            position = max_position + k;
        } else {
            position += k;
        }

        // If the crow reaches or exceeds the target position 'l', return true
        if (position >= l) {
            return true;
        }
    }
    // If after all scarecrows, the crow is at or beyond position 'l', return true
    return position >= l;
}

int main() {
    int t;  // Number of test cases
    cin >> t;
    
    while (t--) {
        int n, k, l;  // Number of scarecrows, teleportation distance, target position
        cin >> n >> k >> l;

        vector<int> scarecrows(n);
        for (int i = 0; i < n; ++i) {
            cin >> scarecrows[i];
        }

        // Binary search for the minimum time
        int low = 0, high = l;
        
        while (low < high) {
            int mid = (low + high) / 2;
            if (canReachWithTime(n, k, l, scarecrows, mid)) {
                high = mid;  // Try to reduce the time
            } else {
                low = mid + 1;  // Increase the time
            }
        }

        // Output twice the minimum time found
        cout << 2 * low << endl;
    }

    return 0;
}
