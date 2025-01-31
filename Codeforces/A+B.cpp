#include <iostream>
using namespace std;

int main() {
    int t; 
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n; 
        int tens = n / 10;
        int units = n % 10; 
        int sum = tens + units;
        cout << sum << endl;
    }
    
    return 0;
}