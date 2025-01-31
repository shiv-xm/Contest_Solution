#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> haystacks(n);
    long long totalHaybales = 0, totalMoves = 0;
    
    // Reading haystacks' ai and bi
    for (int i = 0; i < n; ++i) {
        cin >> haystacks[i].first >> haystacks[i].second;
        totalHaybales += haystacks[i].first;
    }
    
    // Sorting by the initial haybales to help with optimal movement
    sort(haystacks.begin(), haystacks.end());

    // Track the surplus haybales that can be moved
    long long surplus = 0;
    long long moves = 0;

    // Start emptying haystacks and manage surplus
    for (int i = 0; i < n; ++i) {
        int ai = haystacks[i].first;
        int bi = haystacks[i].second;

        // For each haystack, calculate how many haybales we need to move to it
        if (ai > bi) {
            // If haystack i has more haybales than allowed, it's impossible
            cout << -1 << endl;
            return;
        }

        // Move haybales from surplus to this haystack
        long long moveToCurrent = max(0LL, ai - surplus);
        moves += moveToCurrent;
        surplus = max(0LL, surplus + ai - moveToCurrent);

        // Update the surplus after this haystack is emptied
        surplus += bi;
    }

    // The result is the total number of moves required
    cout << moves << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
