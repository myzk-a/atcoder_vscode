#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> ans;
ll L, R;

void dfs(ll l, ll r)
{
    if(L <= l && r <= R)
    {
        ans.emplace_back(l, r);
        return;
    }
    ll c = (l + r) / 2;
    if(L < c) dfs(l, c);
    if(c < R) dfs(c, r);
    return;
}

int main()
{
    cin >> L >> R;

    dfs(0, 1LL << 60LL);

    cout << ans.size() << endl;
    for(auto a : ans) cout << a.first << " " << a.second << endl;

    return 0;
}