#include <bits/stdc++.h>
using namespace std;


int a[300001],c[300001],p[300001];
bool v[300001];
vector<int>t[30001];

void solve(){
  int n, pmin=1e9;
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    p[i]=-1;
    c[i]=0;
    v[i]=false;
    t[i].clear();
  }
  for(int i=1;i<=n;++i){
    p[a[i]]=i;
    t[a[i]].push_back(i);
  }
  for(int i=1;i<=n;++i){
    if(p[i]!=-1){
        c[p[i]]++;
        pmin=min(pmin,p[i]);

    }
    vector<int>r;
  for(int i=1;i<=n;++i){
     if(i==pmin){
        r.push_back(a[i]);
        c[p[a[i]]]--;
        while(c[pmin]==0 and pmin<=n)pmin++;
        i++;
     }
     else{
        if(r.size()%2==0){
            int m=0;
            
  }
        }
     }
  }
  }
}





int main() {
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        solve_single_case(n, a);
    }

    return 0;
}
