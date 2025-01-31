#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define dbg(args...) 42;
#define endl "\n"
#define fo(i, n) for (i = 0; i < (n); ++i)
#define repA(i, j, n) for (i = (j); i <= (n); ++i)
#define repD(i, j, n) for (i = (j); i >= (n); --i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define eb emplace_back
#define X first
#define Y second

using lli = long long int;
using mytype = long double;
using ii = pair<lli, lli>;
using vii = vector<ii>;
using vi = vector<lli>;

int main(){
lli T = 1;
cin >> T;
while (T--)
{
    lli n,m;
    cin>>n>>m;
    lli K = 0;
 
    vii c;
    for(lli i=0;i<n;i++){
        lli l;
        cin>>l;
        set<lli> present;
        for(lli j=0;j<l;j++){
            lli x;
            cin>>x;
            present.insert(x);
        }
 
        vi b;
        lli missing = 0;
        while(sz(b)<2){
            if(!present.count(missing))
                b.push_back(missing);
            missing++;
        }
        c.push_back(ii{b[0],b[1]});
        K=max(K,b[1]);
    }
 
    lli ans = 0;
 
    if(K<m){
        ans+=m*(m+1)/2;
        ans-=K*(K+1)/2;
        m=K;
    }
 
    vi dp(K+1);
    vector<vi> e(K+1);
 
    for(const auto &z:c){
        const lli sm = z.X,sm2=z.Y;
 
        e[sm].push_back(sm2);
        for(lli j=0;j<sm;j++)
            e[j].push_back(sm);
    }
 
    for(lli j=K;j>=0;j--){
        lli &mxReachable=dp[j];
        mxReachable=max(mxReachable,j);
        for(const auto &x:e[j])
            mxReachable=max(mxReachable,dp[x]);
    }
 
    lli maxFromSmallest = 0;
    for(const auto &z:c){
        const lli sm = z.X;
        maxFromSmallest=max(maxFromSmallest,dp[sm]);
    }
 
    for(auto &x:dp)
        x=max(x,maxFromSmallest);
 
    for(lli j=0;j<=m;j++)
        ans+=dp[j];
    cout<<ans<<endl;
 
}  
    return 0;
}