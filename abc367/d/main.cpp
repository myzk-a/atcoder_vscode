#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i];
    vector<ll> S(N + 1, 0);
    ll L = 0;
    for(ll i = 1; i <= N; ++i)
    {
        L += A[i];
        S[i] = S[i-1] + A[i];
    }

    vector<ll> cnt(M + 1, 0);

    ll ans = 0;
    for(ll r = 0; r <= N - 1; ++r)
    {
        ans += cnt[S[r]%M];
        ll tmp = S[r] % M - (L % M);
        if(tmp < 0) tmp += M;
        tmp %= M;
        ans += cnt[tmp];
        ++cnt[S[r]%M];
    }
    cout << ans << endl;
    return 0;
}