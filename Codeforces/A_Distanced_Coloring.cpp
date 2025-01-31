#include <iostream>
#include <cmath> // for ceil function
using namespace std;

int min_colors_needed(int n, int m, int k) {
    // Calculate the number of blocks along the rows and columns
    int blocks_in_rows = (n + k - 1) / k;
    int blocks_in_columns = (m + k - 1) / k;
    
    // The minimum number of colors needed
    return blocks_in_rows * blocks_in_columns;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        int result = min_colors_needed(n, m, k);
        cout << result << endl;
    }
    
    return 0;
}
