#include <iostream>
using namespace std;

int main() {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;

    if (X > Y) {
        // Chef wins
        cout << A << endl;
    } else {
        // Chef loses
        cout << B << endl;
    }

    return 0;
}
