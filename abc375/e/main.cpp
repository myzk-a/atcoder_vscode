#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N + 1), B(N + 1);
    ll sum = 0;
    for(ll i = 1; i <= N; ++i)
    {
        cin >> A[i] >> B[i];
        sum += B[i];
    }

    if(sum % 3 != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    ll x = sum / 3;

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(501, vector<ll>(501, INF)));
    dp[0][0][0] = 0;


    for(ll i = 1; i <= N; ++i)
    {
        for(ll j = 0; j <= 500; ++j)
        {
            for(ll k = 0; k <= 500; ++k)
            {
                if(j - B[i] >= 0 && dp[i - 1][j - B[i]][k] != INF)
                {
                    if(A[i] != 1)
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - B[i]][k] + 1); 
                    }
                    else
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - B[i]][k]);
                    }
                }
                if(k - B[i] >= 0 && dp[i - 1][j][k - B[i]] != INF)
                {
                    if(A[i] != 2)
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - B[i]] + 1);
                    }
                    else
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - B[i]]);
                    }
                }
                if(dp[i- 1][j][k] != INF)
                {
                    if(A[i] != 3)
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 1);
                    }
                    else
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                    }
                }
            }
        }
    }

    ll ans = dp[N][x][x];
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}