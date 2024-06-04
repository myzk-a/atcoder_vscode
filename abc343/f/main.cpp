#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
using ll = long long;
using p = pair<ll, ll>;
using pp = pair<p, p>;

const ll INF = 1LL << 60LL;

pp _op(pp a, p b)
{
    if(a.first.first == b.first)
    {
        a.first.second += b.second;
        return a;
    }
    if(a.second.first == b.first)
    {
        a.second.second += b.second;
        return a;
    }

    if(a.second.first > b.first) return a;

    a.second = b;
    if(a.first.first < a.second.first) swap(a.first, a.second);
    return a;
}

pp op(pp a, pp b)
{
    return (_op(_op(a, b.first), b.second));
}

pp e() {return {{-INF + 1, 0}, {-INF, 0}};}

int main()
{
    ll N, Q;
    cin >> N >> Q;

    segtree<pp, op, e> seg(N);
    for(ll i = 0; i < N; ++i)
    {
        ll a;
        cin >> a;
        seg.set(i, {{a, 1}, {-INF, 0}});
    }

    for(ll i = 0; i < Q; ++i)
    {
        ll t;
        cin >> t;
        if(t == 1)
        {
            ll p, x;
            cin >> p >> x;
            --p;
            seg.set(p, {{x, 1}, {-INF, 0}});
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            --l;
            auto ans = seg.prod(l, r);
            cout << ans.second.second << endl;
        }
    }

    return 0;
}