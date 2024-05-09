#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
struct UnionFind
{
    vector<T> siz, par;
    UnionFind(T N) : siz(N, 1), par(N, -1) {}

    T root(T x)
    {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool is_same(T x, T y)
    {
        return (root(x) == root(y));
    }

    bool unite(T x, T y)
    {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    T size(T x)
    {
        return siz[root(x)];
    }
};

int main()
{
    ll N, M;
    cin >> N >> M;
    map<pair<ll, ll>, ll> edge;
    set<ll> V;
    for(ll i = 0; i < M; ++i)
    {
        ll k, c;
        cin >> k >> c;
        vector<ll> A(k);
        for(auto &a : A) 
        {
            cin >> a;
            V.insert(a);
        }
        for(ll j = 1; j < k; ++j)
        {
            pair<ll, ll> e = {A[0], A[j]};
            if(edge.count(e))
            {
                edge[e] = min(edge[e], c);
            }
            else
            {
                edge[e] = c;
            }
        }
    }

    if(V.size() < N)
    {
        cout << -1 << endl;
        return 0;
    }

    UnionFind<ll> uf(N);
    vector<pair<ll, pair<ll, ll>>> es;
    ll ans = 0;
    for(auto it = edge.begin(); it != edge.end(); ++it)
    {
        es.push_back({it->second, {it->first.first, it->first.second}});
    }
    sort(es.begin(), es.end());

    for(ll i = 0; i < es.size(); ++i)
    {
        ll w = es[i].first;
        ll u = es[i].second.first;
        ll v = es[i].second.second;
        if(uf.is_same(u, v)) continue;
        uf.unite(u, v);
        ans += w;
    }

    cout << ans << endl;

    return 0;
}