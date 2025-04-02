#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353LL;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i];
    vector<ll> S(N + 1, 0);
    for(ll i = 1; i <= N; ++i) S[i] = S[i - 1] + A[i];

    vector<ll> dp(N + 1, 0);
    ll dp_sum = 1;
    map<ll, ll> m;
    m[0] = 1;

    for(ll i = 1; i <= N; ++i)
    {
        dp[i] += dp_sum;
        if(m.count(S[i] - K)) dp[i] -= m[S[i] - K];
        if(dp[i] < 0) dp[i] += MOD;
        dp[i] %= MOD;
        dp_sum += dp[i];
        dp_sum %= MOD;

        if(m.count(S[i]))
        {
            m[S[i]] += dp[i];
            m[S[i]] %= MOD;
        }
        else
        {
            m[S[i]] = dp[i];
        }
    }

    cout << dp[N] << endl;

    return 0;
}