#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num;
    cin>> num;
    if(num%2==0){
        cout <<-1<<endl;
    }else{
        for(int index =num; index >= 1;index -=2){
            cout<<index<< " ";
        }
         for(int index =2; index < num;index +=2){
            cout<<index<< " ";
        }
        cout<<endl;
    }
    }



int main() {
    solve();
    return 0;
}
