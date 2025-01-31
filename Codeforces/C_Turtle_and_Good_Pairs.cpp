#include <bits/stdc++.h>
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
int main()
{
  lli t = 1;
  cin >> t;

  while (t--)
  {

    lli n;
    cin >> n;
    string s;
    cin >> s;

    map<char, lli> freq;
    for (const auto &x : s)
      freq[x]++;

    vector<pair<lli, char>> chrs;
    for (const auto &x : freq)
      chrs.push_back({x.second, x.first});

    sort(all(chrs));
    reverse(all(chrs));

    lli idx = 0;
    string t(n, '$');

    for (const auto &x : chrs)
    {
      lli f = x.first;
      const char c = x.second;
      while (f--)
      {
        if (idx >= n)
          idx = 1;
        t[idx] = c;
        idx += 2;
      }
    }

    lli cur = 0, c = t[0];
    vi cd;
    for (const auto &x : t)
    {
      if (x == c)
        cur++;
      else
      {
        cd.eb(cur);
        cur = 1;
        c = x;
      }
    }

    cd.eb(cur);
    lli det = 0;
    for (lli j = 0; j + 1 < sz(cd); j++)
      det += cd[j] * cd[j + 1];
    dbg(cd, det, t);
    if (sz(cd) > 1)
      assert(det == n - 1);
    cout << t << endl;
  }
  return 0;
}
