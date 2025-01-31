#include <iostream>
#include <vector>           
#include <unordered_set>    
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

        bool valid = true;
        unordered_set<int> occupiedSeats;
        
        // The first seat can be any seat
        occupiedSeats.insert(a[0]);

        for (int i = 1; i < n; i++) {
            // Check if the current seat is adjacent to any already occupied seat
            if (occupiedSeats.count(a[i] - 1) == 0 && occupiedSeats.count(a[i] + 1) == 0) {
                valid = false;
                break;
            }
            occupiedSeats.insert(a[i]);
        }
        
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
