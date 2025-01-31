#include <bits/stdc++.h>
using namespace std;

void RemovalNeed(int n, string s){
    int removals = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            ++removals;
        }
    }
    cout << removals << endl;
}
int main(){
    int n;
    cin>>n;
    string s;
    cin >> s;
    RemovalNeed(n,s);
    return 0;
}