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
    ll N, Q;
    cin >> N >> Q;

    UnionFind<ll> uf(N + 2);
    vector<ll> l(N + 2), r(N + 2), color(N + 2);
    for(ll i = 0; i < N + 2; ++i)
    {
        l[i] = i;
        r[i] = i;
        color[i] = i;
    }

    vector<ll> cnt(N + 2, 1);

    for(ll i = 0; i < Q; ++i)
    {
        ll q;
        cin >> q;
        if(q == 1)
        {
            ll x, c;
            cin >> x >> c;
            ll root = uf.root(x);
            cnt[color[root]] -= uf.size(root);
            color[root] = c;
            cnt[color[root]] += uf.size(root);

            {
                ll l_root = uf.root(l[root] - 1);
                if(color[l_root] == c)
                {
                    ll nl = l[l_root];
                    ll nr = r[root];
                    uf.unite(root, l_root);
                    root = uf.root(root);
                    l[root] = nl;
                    r[root] = nr;
                }
            }

            {
                ll r_root = uf.root(r[root] + 1);
                if(color[r_root] == c)
                {
                    ll nl = l[root];
                    ll nr = r[r_root];
                    uf.unite(root, r_root);
                    root = uf.root(root);
                    l[root] = nl;
                    r[root] = nr;
                }
            }
        }
        else
        {
            ll c;
            cin >> c;
            cout << cnt[c] << endl;
        }
    }

    return 0;
}