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
    ll H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<pair<ll, ll>>> p(Y + 1);
    for(ll i = 0; i < H; ++i)
    {
        for(ll j = 0; j < W; ++j)
        {
            ll a;
            cin >> a;
            if(a <= Y) p[a].push_back({i, j});
        }
    }

    UnionFind<ll> uf(H * W + 1);
    vector<vector<bool>> under(H, vector<bool>(W, false));

    ll dx[] = {-1, 1, 0, 0};
    ll dy[] = {0, 0, -1, 1};

    for(ll y = 1; y <= Y; ++y)
    {
        for(auto v: p[y])
        {
            ll i = v.first;
            ll j = v.second;
            under[i][j] = true;
            ll u = W * i + j; 
            for(ll k = 0; k < 4; ++k)
            {
                ll ni = i + dx[k];
                ll nj = j + dy[k];
                if(ni < 0 || nj < 0 || H <= ni || W <= nj)
                {
                    uf.unite(H * W, u);
                }
                else
                {
                    if(under[ni][nj])
                    {
                        uf.unite(u, W * ni + nj);
                    }
                }
            }
        }
        ll ans = H * W - uf.size(H * W) + 1;
        cout << ans << endl;
    }

    return 0;
}