#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    const ll M = 1e6;
    cin >> N;
    vector<ll> cnt(M + 1);
    for(ll i = 0; i < N; ++i)
    {
        ll a;
        cin >> a;
        ++cnt[a];
    }

    vector<ll> sum(M + 1, 0);
    for(ll i = 1; i <= M; ++i) sum[i] = sum[i-1] + cnt[i];

    ll ans = 0;
    for(ll y = 1; y <= M; ++y)
    {
        ll now = 0;
        for(ll x = 1; x * y <= M; ++x)
        {
            now += x * (sum[min(M, (x + 1) * y - 1)] - sum[x * y - 1] );
        }
        now -= cnt[y];
        ans += now * cnt[y];
        ans += cnt[y] * (cnt[y] - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}