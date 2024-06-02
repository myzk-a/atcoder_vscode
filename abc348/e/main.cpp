#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> to(n);
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<int> c(n);
  rep(i,n) cin >> c[i];

  ll tot = 0;
  rep(i,n) tot += c[i];

  int x = -1;
  {
    auto dfs = [&](auto dfs, int v, int p=-1) -> ll {
      ll res = c[v];
      ll mx = 0;
      for (int u : to[v]) if (u != p) {
        ll now = dfs(dfs,u,v);
        mx = max(mx, now);
        res += now;
      }
      mx = max(mx, tot-res);
      if (mx*2 <= tot) x = v;
      return res;
    };
    dfs(dfs,0);
  }

  ll ans = 0;
  auto dfs = [&](auto dfs, int v, int dist=0, int p=-1) -> void {
    ans += (ll)dist*c[v];
    for (int u : to[v]) if (u != p) {
      dfs(dfs,u,dist+1,v);
    }
  };
  dfs(dfs,x);
  cout << ans << endl;
  return 0;
}