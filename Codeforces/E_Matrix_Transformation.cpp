#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;  // number of test cases
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> A(n, vector<int>(m));
        vector<vector<int>> B(n, vector<int>(m));
        
        // Read matrix A
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }
        
        // Read matrix B
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> B[i][j];
            }
        }
        
        bool possible = true;
        
        // Check the condition A[i][j] & B[i][j] == B[i][j] for all elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((A[i][j] & B[i][j]) != B[i][j]) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
        }
        
        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
