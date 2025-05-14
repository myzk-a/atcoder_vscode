#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

ll op(ll a, ll b) {return min(a, b);}
ll e() {return INF;}

ll m(ll f, ll x) {return min(f, x);}
ll comp(ll f, ll g) {return min(f, g);}
ll id() {return INF;}

int main()
{
    ll H, W, N;
    cin >> H >> W >> N;
    vector<tuple<ll, ll, ll, ll>> t;

    for(ll i = 0; i < N; ++i)
    {
        ll r, c, l;
        cin >> r >> c >> l;
        --c;
        t.emplace_back(r, c, c + l, i);
    }

    sort(t.rbegin(), t.rend());

    atcoder::lazy_segtree<ll, op, e, ll, m, comp, id> seg(vector<ll>(W, H));

    vector<ll> ans(N);
    for(auto [_, l, r, num] : t)
    {
        ll h = seg.prod(l, r);
        ans[num] = h;
        seg.apply(l, r, h - 1);
    }
    for(auto a : ans) cout << a << endl;
    return 0;
}