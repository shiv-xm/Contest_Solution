#include <iostream>
#include <vector>
using namespace std;

// Function to generate k distinct points
void generatePoints(int xc, int yc, int k) {
    int count = 0;
    int x_offset = 0, y_offset = 0;

    for (int i = 0; i < k; ++i) {
        cout << xc + x_offset << " " << yc + y_offset << endl;

        // Move to the next point in a grid pattern
        x_offset += 1;
        if (x_offset >= 3) { // Adjust this threshold to change the grid size
            x_offset = 0;
            y_offset -= 1;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int xc, yc, k;
        cin >> xc >> yc >> k;

        generatePoints(xc, yc, k);
    }

    return 0;
}
