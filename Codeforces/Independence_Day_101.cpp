#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;

        int maxStrips = max({A, B, C});
        int sumOfOthers = A + B + C - maxStrips;

        if (maxStrips <= sumOfOthers + 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
