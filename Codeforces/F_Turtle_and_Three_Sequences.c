#include <stdio.h>
#include <limits.h>

#define MAX_N 3000
#define MAX_M 5

int dp[MAX_M + 1][MAX_N];

int max_subsequence_sum(int n, int m, int a[], int b[], int c[]) {
    // Initialize DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    
    // Base case: empty subsequence
    for (int j = 0; j < n; j++) {
        dp[0][j] = 0;
    }
    
    // Fill DP table
    for (int length = 1; length <= m; length++) {
        for (int j = 0; j < n; j++) {
            if (length == 1) {
                dp[length][j] = c[j];
            } else {
                for (int k = 0; k < j; k++) {
                    if (a[k] <= a[j] && b[k] != b[j]) {
                        if (dp[length - 1][k] != INT_MIN) {
                            dp[length][j] = (dp[length][j] > dp[length - 1][k] + c[j]) ? dp[length][j] : dp[length - 1][k] + c[j];
                        }
                    }
                }
            }
        }
    }
    
    // Get the result
    int result = INT_MIN;
    for (int j = 0; j < n; j++) {
        if (dp[m][j] > result) {
            result = dp[m][j];
        }
    }
    
    return result == INT_MIN ? -1 : result;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        int a[n], b[n], c[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
        }
        
        int result = max_subsequence_sum(n, m, a, b, c);
        printf("%d\n", result);
    }
    
    return 0;
}
