#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool matchesTemplate(const vector<int>& a, const string& s) {
    unordered_map<int, char> numToChar;
    unordered_map<char, int> charToNum;
    
    int n = a.size();
    
    for (int i = 0; i < n; ++i) {
        int num = a[i];
        char c = s[i];
        
        if (numToChar.count(num) && numToChar[num] != c) return false;
        if (charToNum.count(c) && charToNum[c] != num) return false;
        
        numToChar[num] = c;
        charToNum[c] = num;
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        int m;
        cin >> m;
        
        while (m--) {
            string s;
            cin >> s;
            
            if (s.size() != n) {
                cout << "NO" << endl;
            } else if (matchesTemplate(a, s)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}
