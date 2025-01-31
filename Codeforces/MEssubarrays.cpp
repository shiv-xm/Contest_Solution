#include <iostream>
#include <vector>
using namespace std;

// Function to generate the permutation q that is the reverse of the sorted sequence
void generatePermutation(int n) {
    for (int i = n; i >= 1; --i) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Read and ignore the permutation p (it's not needed for this solution)
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        // Generate and output the permutation q
        generatePermutation(n);
    }

    return 0;
}
