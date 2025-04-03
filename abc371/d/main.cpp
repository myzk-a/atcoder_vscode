#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> X(N), P(N);
    for(auto &x : X) cin >> x;
    for(auto &p : P) cin >> p;
    ll Q;
    cin >> Q;
    vector<ll> L(Q), R(Q);
    for(ll i = 0; i < Q; ++i) cin >> L[i] >> R[i];

    set<ll> S;
    for(auto x : X) S.insert(x);
    for(auto l : L) S.insert(l);
    for(auto r : R) S.insert(r);
    vector<ll> v;
    for(auto s : S) v.push_back(s);

    map<ll, ll> m;
    for(ll i = 0; i < v.size(); ++i) m[v[i]] = i;

    vector<ll> C(v.size() + 1, 0);
    for(ll i = 0; i < N; ++i)
    {
        C[m[X[i]] + 1] += P[i];
    }
    for(ll i = 1; i < C.size(); ++i)
    {
        C[i] += C[i - 1];
    }

    for(ll i = 0; i < Q; ++i)
    {
        ll l = L[i];
        ll r = R[i];
        ll ans = C[m[r] + 1] - C[m[l]];
        cout << ans << endl;
    }

    return 0;
}