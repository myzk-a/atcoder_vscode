#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> d(M + 1, 1);
    for(ll i = 0; i < N; ++i)
    {
        ll l, r;
        cin >> l >> r;
        d[r] = max(d[r], l + 1);
    }

    for(ll r = 1; r <= M; ++r) d[r] = max(d[r], d[r - 1]);

    ll ans = 0;
    for(ll r = 1; r <= M; ++r) ans += r - d[r] + 1;
    cout << ans << endl;
    return 0;
}