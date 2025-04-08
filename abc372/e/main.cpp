#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> m = {};

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

        vector<ll> v = m[x];

        for(auto s : m[y])
        {
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector<ll> _v;
        for(ll i = 0; i < min(10LL, (ll)v.size()); ++i) _v.push_back(v[i]);
        m[x] = _v;

        return true;
    }

    T size(T x)
    {
        return siz[root(x)];
    }
};

int main()
{
    ll N, Q;
    cin >> N >> Q;
    for(ll i = 0; i < N; ++i)
    {
        m[i].push_back(i);
    }

    UnionFind<ll> uf(N);

    for(ll i = 0; i < Q; ++i)
    {
        ll q;
        cin >> q;
        if(q == 1)
        {
            ll u, v;
            cin >> u >> v;
            --u;
            --v;
            uf.unite(u, v);
        }
        else
        {
            ll v, k;
            cin >> v >> k;
            --v;
            if(uf.size(v) < k) cout << -1 << endl;
            else
            {
                ll root = uf.root(v);
                --k;
                cout << m[root][k] + 1 << endl;
            }
        }
    }
    return 0;
}