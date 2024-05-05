#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return (x1 - x2) * (x1 - x2) + (y1- y2) * (y1 - y2);
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> X(N + 1), Y(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> X[i] >> Y[i];

    for(ll i = 1; i <= N; ++i)
    {
        ll ans = -1;
        ll d = -1;
        for(ll j = 1; j <= N; ++j)
        {
            ll tmp_dist = dist(X[i], Y[i], X[j], Y[j]);
            if(tmp_dist > d)
            {
                d = tmp_dist;
                ans = j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}