#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int min_operations_to_alternating(string s) {
    int n = s.length();
    if (n % 2 != 0) return 1; // If length is odd, we need to delete one character

    int even_count = 0, odd_count = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[0]) even_count++;
    }
    for (int i = 1; i < n; i += 2) {
        if (s[i] != s[1]) odd_count++;
    }

    return min(even_count, odd_count);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << min_operations_to_alternating(s) << endl;
    }
    return 0;
}
