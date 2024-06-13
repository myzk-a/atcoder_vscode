#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

int main()
{
    ll N, M;
    cin >> N >> M;
    Graph g(N);
    vector<set<ll>> parent(N);
    for(ll i = 0; i < M; ++i)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        g[v].push_back(u);
        parent[u].insert(v);
    }

    vector<ll> vs;
    for(ll i = 0; i < N; ++i)
    {
        if(parent[i].size() == 0)
        {
            vs.push_back(i);
        }
    }

    if(vs.size() > 1)
    {
        cout << "No" << endl;
        return 0;
    }

    auto dfs = [&](auto dfs, ll v) -> bool
    {
        set<ll> candidate;
        for(auto nv : g[v])
        {
            parent[nv].erase(v);
            if(parent[nv].size() == 0) candidate.insert(nv);
        }

        if(candidate.size() >= 2)
        {
            return false;
        }
        if(candidate.size() == 1)
        {
            vs.push_back(*candidate.begin());
            auto f = dfs(dfs, *candidate.begin());
            return f;
        }
        return true;
    };

    auto f = dfs(dfs, vs[0]);
    if(f)
    {
        vector<ll> ans(N, 0);
        for(ll i = 0; i < N; ++i)
        {
            ans[vs[i]] = N - i;
        }
        cout << "Yes" << endl;
        for(auto a : ans) cout << a << " ";
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}