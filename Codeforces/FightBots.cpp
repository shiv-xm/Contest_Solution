#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool canBobWin(int N, int X, int Y, const string& S) {
    unordered_set<string> alice_positions;
    int alice_x = 0, alice_y = 0;
    alice_positions.insert(to_string(alice_x) + "," + to_string(alice_y));

    for (char move : S) {
        if (move == 'L') alice_x--;
        else if (move == 'R') alice_x++;
        else if (move == 'U') alice_y++;
        else if (move == 'D') alice_y--;
        alice_positions.insert(to_string(alice_x) + "," + to_string(alice_y));
    }

    int bob_x = X, bob_y = Y;
    for (int i = 0; i < N; i++) {
        if (alice_positions.count(to_string(bob_x) + "," + to_string(bob_y))) {
            return true;
        }
        if (bob_x > alice_x) bob_x--;
        else if (bob_x < alice_x) bob_x++;
        if (bob_y > alice_y) bob_y--;
        else if (bob_y < alice_y) bob_y++;
    }

    return alice_positions.count(to_string(bob_x) + "," + to_string(bob_y));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;
        string S;
        cin >> S;
        if (canBobWin(N, X, Y, S)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
