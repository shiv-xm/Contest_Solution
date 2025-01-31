#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B; // Input Alice's and Bob's initial slices
        
        int totalSlicesEaten = 0; // Tracks total slices eaten by Charlie

        // Continue while Alice and Bob are unhappy
        while (A != B) {
            if (A > B) {
                // If Alice has more slices, Charlie eats half of Alice's slices
                int slicesEaten = (A + 1) / 2; // Half, rounded up
                A -= slicesEaten;
                totalSlicesEaten += slicesEaten;
            } else {
                // If Bob has more slices, Charlie eats half of Bob's slices
                int slicesEaten = (B + 1) / 2; // Half, rounded up
                B -= slicesEaten;
                totalSlicesEaten += slicesEaten;
            }
        }
        
        // Output the total slices Charlie ate for this test case
        cout << totalSlicesEaten << endl;
    }

    return 0;
}
