#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll P = (1LL << 61LL) - 1;


mt19937_64 rng(58);

int main()
{
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N + 1), B(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i];
    for(ll i = 1; i <= N; ++i) cin >> B[i];

    vector<ull> h(200007LL, 0);
    for(ll i = 0; i < h.size(); ++i) h[i] = rng() % P;

    vector<ll> sa(N + 1, 0), sb(N + 1, 0);
    for(ll i = 1; i <= N; ++i)
    {
        sa[i] = (sa[i - 1] + h[A[i]]) % P;
        sb[i] = (sb[i - 1] + h[B[i]]) % P;
    }

    for(ll i = 0; i < Q; ++i)
    {
        ll l, r, L, R;
        cin >> l >> r >> L >> R;
        ll s1 = sa[r] - sa[l - 1];
        if(s1 < 0) s1 += P;
        s1 %= P;

        ll s2 = sb[R] - sb[L - 1];
        if(s2 < 0) s2 += P;
        s2 %= P;
        if(s1 == s2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}