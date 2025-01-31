#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int specialIndex = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != 1 && a[i] != -1) {
                specialIndex = i;
            }
        }
        
        set<int> subarraySums;
        subarraySums.insert(0); // Empty subarray sum
        
        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            if (i == specialIndex) continue;
            leftSum += a[i];
            subarraySums.insert(leftSum);
        }

        if (specialIndex != -1) {
            int x = a[specialIndex];
            set<int> newSums;
            for (int s : subarraySums) {
                newSums.insert(s + x);
            }
            subarraySums.insert(newSums.begin(), newSums.end());
        }

        cout << subarraySums.size() << endl;
        for (int sum : subarraySums) {
            cout << sum << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
