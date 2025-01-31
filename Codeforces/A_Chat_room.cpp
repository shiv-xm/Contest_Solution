#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    string target = "hello";
    int j = 0; // index for the target string "hello"
    
    // Iterate through the input string
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == target[j]) {
            j++;
        }
        // If all characters of "hello" are found, break
        if (j == target.length()) {
            break;
        }
    }
    
    // Check if we have matched all characters of "hello"
    if (j == target.length()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
