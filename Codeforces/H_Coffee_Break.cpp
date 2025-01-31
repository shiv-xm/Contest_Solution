#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> result(n);

        // For each coffee machine i, we calculate the max number of students that can be around it
        for (int i = 0; i < n; i++) {
            int max_students = a[i];

            // Leftward adjustment (from a[i-1] to a[i])
            if (i > 0) {
                int move_left = a[i - 1] / 2;
                max_students += move_left;
            }

            // Rightward adjustment (from a[i+1] to a[i])
            if (i < n - 1) {
                int move_right = a[i + 1] / 2;
                max_students += move_right;
            }

            result[i] = max_students;
        }

        // Output result for this test case
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
