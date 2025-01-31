#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        int w;
        cin >> w;
        
        vector<long long> heights(w);
        for (int i = 0; i < w; i++) {
            cin >> heights[i];
        }

        // Sort the gorilla heights in descending order
        sort(heights.rbegin(), heights.rend());

        // Number of cells in a k x k sub-square
        int cellsInSubSquare = k * k;
        
        // Maximum number of gorillas we can use
        int numberOfGorillasToUse = min(cellsInSubSquare, w);
        
        // Calculate the maximum possible spectacle
        long long maxSpectacle = 0;
        for (int i = 0; i < numberOfGorillasToUse; i++) {
            maxSpectacle += heights[i];
        }

        // Output the result for the current test case
        cout << maxSpectacle << endl;
    }

    return 0;
}
