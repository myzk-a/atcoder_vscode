#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

void dfs(ll v, Graph &g, vector<bool> &check, set<ll> &V)
{
    V.insert(v);
    check[v] = true;
    for(auto nv : g[v])
    {
        if(check[nv]) continue;
        dfs(nv, g, check, V);
    }
    return;
}

int main()
{
    ll N, M;
    cin >> N >> M;

    Graph g(N);
    map<ll, ll> cnt;
    for(ll i = 0; i < M; ++i)
    {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
        if(cnt.count(a))
        {
            ++cnt[a];
        }
        else
        {
            cnt[a] = 1;
        }
    }

    vector<bool> check(N, false);

    ll ans = 0;

    for(ll v = 0; v < N; ++v)
    {
        if(check[v]) continue;
        set<ll> V;
        dfs(v, g, check, V);
        ll num_edges = (V.size() * (V.size() - 1)) / 2;
        for(auto u : V)
        {
            num_edges -= cnt[u];
        }
        ans += num_edges;
    }

    cout << ans << endl;

    return 0;
}