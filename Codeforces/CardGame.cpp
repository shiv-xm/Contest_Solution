#include <iostream>
using namespace std;

int countSuneetWins(int a1, int a2, int b1, int b2) {
    int winCount = 0;
    
    int suneetCards[2] = {a1, a2};
    int slavicCards[2] = {b1, b2};

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
        
            int suneetFirst = suneetCards[i];
            int suneetSecond = suneetCards[1 - i];
            
            int slavicFirst = slavicCards[j];
            int slavicSecond = slavicCards[1 - j];

            int winsSuneet = 0;

            if (suneetFirst > slavicFirst) ++winsSuneet;
            if (suneetSecond > slavicSecond) ++winsSuneet;
            if (winsSuneet > 1) ++winCount;
        }
    }

    return winCount;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        cout << countSuneetWins(a1, a2, b1, b2) << endl;
    }

    return 0;
}
