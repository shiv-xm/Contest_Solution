#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to calculate the minimum length of the binary string
int minFinalLength(const string& S) {
    int length = S.length();
    int operations = 0;

    // Traverse the string to count pairs of different adjacent characters
    for (int i = 0; i < length - 1; ++i) {
        if (S[i] != S[i + 1]) {
            ++operations;
            ++i; // Skip the next character as it will be removed
        }
    }

    // Final length = original length - number of operations (pairs removed * 2)
    return length - (operations * 2);
}

int main() {
    int T; // Number of test cases
    cin >> T;

    vector<int> results; // Store results for each test case
    while (T--) {
        int N; // Length of the binary string
        cin >> N;
        string S; // Binary string
        cin >> S;

        // Calculate and store the result for the current test case
        results.push_back(minFinalLength(S));
    }

    // Output results for all test cases
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
