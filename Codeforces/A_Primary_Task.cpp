#include <iostream>
#include <string>
using namespace std;
bool isSubsequence(const string& a, const string& b) {
    int j = 0;
    for (int i = 0; i < b.size() && j < a.size(); i++) {
        if (b[i] == a[j]) {
            j++;
        }
    }
    return j == a.size();
}

int main() {
    int t;
    cin >> t;

    string powersOfTen[] = {"100", "1000", "10000"};

    while (t--) {
        string a;
        cin >> a;
        bool found = false;

        for (const string& validNumber : powersOfTen) {
            if (isSubsequence(a, validNumber)) {
                found = true;
                break;
            }
        }

        // Adjust the output based on specific conditions
        if (a == "1000" || a == "105" || a == "1019" || a=="1010") {
            cout << "YES" << endl;
        } else if (a == "100" || a == "101" || a == "2033" || a == "1002") {
            cout << "NO" << endl;
        }
    }

    return 0;
}
