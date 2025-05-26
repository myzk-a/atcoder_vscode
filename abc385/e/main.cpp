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

    ll max_size = 0;
    for(ll v = 0; v < N; ++v)
    {
        vector<ll> tmp;
        for(auto nv : g[v]) tmp.push_back(g[nv].size());

        sort(tmp.rbegin(), tmp.rend());
        for(ll i = 0; i < tmp.size(); ++i)
        {
            ll y = tmp[i];
            max_size = max(max_size, y * (i + 1));
        }
    }

    ll ans = N - (max_size + 1);
    cout << ans << endl;
    return 0;
}