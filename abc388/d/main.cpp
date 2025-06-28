#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
using ll = long long;

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(auto &a : A) cin >> a;

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

    for(ll i = 0; i < N; ++i)
    {
        ll value = seg.get(i);
        ll tmp = min(N - i - 1, value);
        seg.set(i, value - tmp);
        seg.apply(i + 1, i + tmp + 1, 1);
    }
    for(ll i = 0; i < N; ++i) cout << seg.get(i) << " ";
    cout << endl;
    return 0;
}