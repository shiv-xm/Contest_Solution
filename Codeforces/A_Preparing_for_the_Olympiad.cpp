#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            int m = dp[i - 1] + a[i - 1];
            int s = (i < n ? b[i] : 0); 
            dp[i] = max(dp[i], m - s);
        }

        cout << dp[n] << endl;
    }
    return 0;
}
