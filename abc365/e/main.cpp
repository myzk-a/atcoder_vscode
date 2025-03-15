#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N + 1);
    ll sum = 0;
    for(ll i = 1; i <= N; ++i)
    {
        cin >> A[i];
        sum += A[i];
    }

    vector<ll> S(N + 1, 0);
    for(ll i = 1; i <= N; ++i) S[i] = S[i-1] ^ A[i];
    ll ans = 0;
    for(ll k = 0; k <= 30; ++k)
    {
        ll cnt_0 = 0;
        ll cnt_1 = 0;
        for(ll i = 0; i <= N; ++i)
        {
            if((S[i] & (1LL << k)) != 0)
            {
                ++cnt_1;
            }
            else
            {
                ++cnt_0;
            }
        }
        ans += (cnt_0 * cnt_1) * (1LL << k);
    }

    ans -= sum;
    cout << ans << endl;

    return 0;
}