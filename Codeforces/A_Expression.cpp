#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b>> c;
    
    int r1 = a + b + c ;
    int r2 = a * b * c ;
    int r3 = (a + b) * c;
    int r4 = a * (b + c);

    int max_result = max({r1, r2, r3, r4});

     cout << max_result << endl;

     return 0;
}