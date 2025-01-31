#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; 

    int home[30], guest[30]; 
    for (int i = 0; i < n; i++) {
        cin >> home[i] >> guest[i];
    }
    int conflict_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && home[i] == guest[j]) {
                conflict_count++;
            }
        }
    }

    cout << conflict_count << endl; 
    return 0;
}
