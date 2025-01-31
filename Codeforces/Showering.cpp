#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        vector<pair<int, int>> intervals(n);
        for (int i = 0; i < n; ++i) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        bool canShower = false;
        
        if (intervals[0].first >= s) {
            canShower = true;
        }

        for (int i = 1; i < n; ++i) {
            if (intervals[i].first - intervals[i - 1].second >= s) {
                canShower = true;
            }
        }

        if (m - intervals[n - 1].second >= s) {
            canShower = true;
        }

        if (canShower) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
