#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        
        long long d = r - l; 
        
        
        
        long long k = sqrt(2 * d + 0.25) + 0.5;
        
        cout << k << endl;
    }
    
    return 0;
}
