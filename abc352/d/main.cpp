#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> P[i];
    vector<ll> Q(N + 1);
    for(ll i = 1; i <= N; ++i) Q[P[i]] = i;

    set<ll> S;
    for(ll i = 1; i <= K; ++i) S.insert(Q[i]);
    auto itr = S.end();
    --itr;
    ll ans = *itr - *S.begin();

    for(ll i = K + 1; i <= N; ++i)
    {
        S.erase(Q[i-K]);
        S.insert(Q[i]);
        itr = S.end();
        --itr;
        ans = min(ans, *itr - *S.begin());
    }

    cout << ans << endl;

    return 0;
}