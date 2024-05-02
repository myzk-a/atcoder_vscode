#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> C(N);
    for(auto &c : C) cin >> c;

    vector<vector<ll>> dp(N, vector<ll>(4, INF));
    if(S[0] == '0')
    {
        dp[0][0] = 0;
        dp[0][2] = C[0];
    }
    else
    {
        dp[0][2] = 0;
        dp[0][0] = C[0];
    }

    for(ll i = 1; i < N; ++i)
    {
        if(S[i] == '0')
        {
            dp[i][0] = dp[i - 1][2];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][3]);
            dp[i][2] = min(dp[i][2], dp[i - 1][0] + C[i]);
            dp[i][3] = min(dp[i][3], dp[i - 1][2] + C[i]);
            dp[i][3] = min(dp[i][3], dp[i - 1][1] + C[i]);
        }
        else
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][2] + C[i]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + C[i]);
            dp[i][1] = min(dp[i][1], dp[i - 1][3] + C[i]);
            dp[i][2] = dp[i- 1][0];
            dp[i][3] = min(dp[i - 1][2], dp[i - 1][1]);
        }
    }

    auto ans = min(dp[N - 1][1], dp[N-1][3]);

    cout << ans << endl;

    return 0;
}