#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353LL;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N + 1), B(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i] >> B[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(ll i = 1; i <= N - 1; ++i)
    {
        if(A[i + 1] != A[i])
        {
            dp[i + 1][0] += dp[i][0];
            dp[i + 1][0] %= MOD;
        } 
        if(A[i + 1] != B[i])
        {
            dp[i + 1][0] += dp[i][1];
            dp[i + 1][0] %= MOD;
        }
        if(B[i + 1] != A[i])
        {
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][1] %= MOD;
        }
        if(B[i + 1] != B[i])
        {
            dp[i + 1][1] += dp[i][1];
            dp[i + 1][1] %= MOD;
        }
    }

    ll ans = (dp[N][0] + dp[N][1]) % MOD;
    cout << ans << endl;

    return 0;
}