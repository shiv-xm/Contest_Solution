#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, Petya, Vasya, Tonya, number(0);
    cin >> n;
    while (n--)
    {
        cin >> Petya >> Vasya >> Tonya;
        if (Petya + Vasya + Tonya >= 02)
        {
            number += 1;
        }
    }
    cout << number << endl;
    return 0;
}