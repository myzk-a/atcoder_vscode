#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(2, -1));
    dp[0][0] = 0;
    for(ll i = 1; i <= N; ++i)
    {
        //倒さない
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];

        //倒す
        if(dp[i - 1][1] != -1)
        {
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + A[i] * 2);
        }
        if(dp[i - 1][0] != -1)
        {
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + A[i]);
        }
    }

    ll ans = max(dp[N][1], dp[N][0]);
    cout << ans << endl;

    return 0;
}