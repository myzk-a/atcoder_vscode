#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge
{
    ll to;
    ll w;
    Edge(ll to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main()
{
    ll N, M;
    cin >> N >> M;
    Graph g(N);
    for(ll i = 0; i < M; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].push_back(Edge(v, w));
        g[v].push_back(Edge{u, -w});
    }
    vector<ll> ans(N, 0);
    vector<ll> checked(N, false);

    auto f = [&](auto f, ll v) -> void
    {
        checked[v] = true;
        for(auto e : g[v])
        {
            if(checked[e.to]) continue;
            ll val = e.w + ans[v];
            ans[e.to] = val;
            f(f, e.to);
        }
    };
    for(ll i = 0; i < N; ++i)
    {
        if(checked[i]) continue;
        ans[i] = 0;
        f(f, i);
    }

    for(auto a : ans) cout << a << " ";
    cout << endl;
    return 0;
}