#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1); 
    map<int, int> freq;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    sort(a.begin() + 1, a.end(), [&](int x, int y) {
        if (freq[x] != freq[y]) 
            return freq[x] < freq[y];
        return x < y;
    });

   
    for (int i = 1; i <= k; ++i) {
        if (--freq[a[i]] == 0) 
            freq.erase(a[i]);
        a[i] = a[n];
        freq[a[i]]++;
    }

    cout << freq.size() << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) 
    solve();
    return 0;
}
