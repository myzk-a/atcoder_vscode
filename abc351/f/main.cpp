#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
using ll = long long;

ll op(ll a, ll b){return a + b;}
ll e() {return 0;}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (auto& a : A) cin >> a;

    // 座標圧縮
    set<ll> S;
    for(auto a : A) S.insert(a);
    vector<ll> q;
    for(auto s : S) q.push_back(s);
    map<ll, ll> conv;
    for(ll i = 0; i < q.size(); ++i)
    {
        conv[q[i]] = i;
    }

    const ll M = q.size() + 2;
    vector<ll> sum(M, 0), cnt(M, 0);

    for (auto a : A)
    {
        sum[conv[a]] += a;
        ++cnt[conv[a]];
    }

    segtree<ll, op, e> seg_sum(sum);
    segtree<ll, op, e> seg_cnt(cnt);

    ll ans = 0;
    for (ll i = 0; i < N; ++i)
    {
        ll tmp = seg_sum.get(conv[A[i]]);
        seg_sum.set(conv[A[i]], tmp - A[i]);

        tmp = seg_cnt.get(conv[A[i]]);
        seg_cnt.set(conv[A[i]], tmp - 1);

        ll s = seg_sum.prod(conv[A[i]], M);
        ll c = seg_cnt.prod(conv[A[i]], M);
        ans += s - A[i] * c;
    }

    cout << ans << endl;

    return 0;
}