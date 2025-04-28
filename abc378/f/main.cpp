#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

int main()
{
    ll N;
    cin >> N;
    Graph g(N);
    for(ll i = 0; i < N - 1; ++i)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = 0;
    vector<ll> deg(N);
    vector<ll> dp(N);

    for(ll i = 0; i < N; ++i) deg[i] = g[i].size();

    auto f = [&](auto f, ll v, ll p) -> void
    {
        for(auto nv : g[v])
        {
            if(p == nv) continue;
            f(f, nv, v);
            if(deg[v] == 3)
            {
                ans += dp[v] * dp[nv];
                dp[v] += dp[nv];
            }
            if(deg[v] == 2)
            {
                ans += dp[nv];
            }
        }
        if(deg[v] == 2) ++dp[v];
    };

    f(f, 0, -1);

    for(ll i = 0; i < N; ++i)
    {
        for(ll j : g[i])
        {
            if(i < j && deg[i] == 2 && deg[j] == 2) --ans;
        }
    }

    cout << ans << endl;

    return 0;
}