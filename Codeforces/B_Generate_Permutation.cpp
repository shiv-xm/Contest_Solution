#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << -1 << endl;
        } else {
            vector<int> perm(n);
            int left = 1, right = n;

            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    perm[i] = left;
                    left++;
                } else {
                    perm[i] = right;
                    right--;
                }
            }

            for (int i = 0; i < n; i++) {
                cout << perm[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
