#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 30LL;
const ll M = 10000LL;
ll dp[81][10001][81];

int main()
{
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N + 1), B(N + 1);
    ll sum_a = 0;
    ll sum_b = 0;
    for(ll i = 1; i <= N; ++i) 
    {
        cin >> A[i] >> B[i];
        sum_a += A[i];
        sum_b += B[i];
    }
    if(sum_a <= X && sum_b <= Y)
    {
        cout << N << endl;
        return 0;
    }

    for (ll i = 0; i < 81; ++i)
    {
        for (ll j = 0; j <= M; ++j)
        {
            for (ll k = 0; k < 81; ++k)
            {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    for(ll i = 1; i <= N; ++i)
    {
        for(ll j = 0; j <= M; ++j)
        {
            for(ll k = 0; k <= i; ++k)
            {
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
                if(j - A[i] >= 0 && k >= 1)
                {
                   dp[i][j][k] = min(dp[i][j][k], dp[i-1][j - A[i]][k - 1] + B[i]);
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i <= X; ++i)
    {
        for(ll j = 0; j <= N; ++j)
        {
            if(dp[N][i][j] > Y) continue;
            ans = max(ans, j);
        }
    }
    if(ans < N) ++ans;

    cout << ans << endl;

    return 0;
}