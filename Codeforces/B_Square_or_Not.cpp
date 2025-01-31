#include <iostream>
#include <cmath>
using namespace std;

// Function to check if n is a perfect square
bool is_Square_matrix(const string &s, int n) {
    int side = sqrt(n);
    if (side * side != n) return false; // Check if it's a perfect square

    // Check top and bottom borders
    for (int i = 0; i < side; i++) {
        if (s[i] != '1' || s[(side - 1) * side + i] != '1') {
            return false;
        }
    }

    // Check left and right borders
    for (int i = 0; i < side; i++) {
        if (s[i * side] != '1' || s[i * side + (side - 1)] != '1') {
            return false;
        }
    }

    // Check inner elements
    for (int i = 1; i < side - 1; i++) {
        for (int j = 1; j < side - 1; j++) {
            if (s[i * side + j] != '0') return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;  // Read the number of test cases
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;  // Read the length of the string and the string itself
        
        if (is_Square_matrix(s, n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
