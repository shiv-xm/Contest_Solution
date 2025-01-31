#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n), c(n);
        long long ans = 0;

        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        for (int i = 0; i < n; ++i) {
            c[i] = a[i] - b[i];
            if (c[i] < 0) {
                ans -= c[i];
            }
        }

        bool flag = true;

        for (int i = 0; i < n; ++i) {
            if ((c[i] < 0 && ans > -c[i]) || (c[i] >= 0 && c[i] < ans)) {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
