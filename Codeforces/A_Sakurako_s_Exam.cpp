#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int total_sum = a + 2 * b;

        // Check if the total sum is even
        if (total_sum % 2 == 1) {
            cout << "NO" << endl;
        }
        else {
            // Check if we have enough 1's to balance the odd 2's
            if (a == 0 && b % 2 == 1) {
                cout << "NO" << endl; // No 1's to balance an odd number of 2's
            }
            else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
