#include <iostream>
#include <string>

using namespace std;

bool canPlaceSubsequence(const string& s, const string& t) {
    int s_index = 0, t_index = 0;
    int s_len = s.length(), t_len = t.length();
    
    while (s_index < s_len && t_index < t_len) {
        if (s[s_index] == t[t_index] || s[s_index] == '?') {
            ++t_index;
        }
        ++s_index;
    }
    
    return t_index == t_len;
}

string replaceQuestionMarks(string s, const string& t) {
    int t_index = 0;
    for (char& ch : s) {
        if (ch == '?') {
            if (t_index < t.length()) {
                ch = t[t_index++];
            } else {
                ch = 'a'; // If no specific requirement, replace remaining '?' with 'a'
            }
        }
    }
    return s;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        
        if (canPlaceSubsequence(s, t)) {
            cout << "YES" << endl;
            string result = replaceQuestionMarks(s, t);
            cout << result << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
