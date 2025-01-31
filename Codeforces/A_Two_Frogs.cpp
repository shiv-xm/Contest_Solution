#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (abs(b - a) % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
