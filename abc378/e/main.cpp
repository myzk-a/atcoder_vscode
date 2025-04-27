#include <bits/stdc++.h>
#include<atcoder/segtree.hpp>
using namespace atcoder;
using namespace std;
using ll = long long;

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i];
    vector<ll> S(N + 1, 0);
    for(ll i = 1; i <= N; ++i)
    {
        S[i] = (S[i - 1] + A[i]) % M;
    }

    ll ans = 0;
    for(ll r = 1; r <= N; ++r) ans += r * S[r];
    for(ll l = 0; l <= N - 1; ++l) ans -= S[l] * (N - l);

    vector<ll> v(M + 1, 0);
    segtree<ll, op, e> seg(v);

    ll cnt = 0;
    for(ll i = 0; i <= N; ++i)
    {
        cnt += i - seg.prod(0, S[i] + 1);
        ll tmp = seg.get(S[i]);
        seg.set(S[i], tmp + 1);
    }

    ans += cnt * M;
    cout << ans << endl;

    return 0;
}