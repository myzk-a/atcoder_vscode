#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N + 1), A(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> X[i];
    for(ll i = 1; i <= N; ++i) cin >> A[i];

    if(K == 0)
    {
        for(ll i = 1; i <= N; ++i) cout << A[i] << " ";
        cout << endl;
        return 0;
    }

    vector<vector<ll>> dp(61, vector<ll>(N + 1, 0));
    for(ll i = 1; i <= N; ++i) dp[0][i] = X[i];
    for(ll k = 1; k <= 60; ++k)
    {
        for(ll i = 1; i <= N; ++i)
        {
            dp[k][i] = dp[k - 1][dp[k - 1][i]];
        }
    }


    vector<ll> ans;
    --K;
    for(ll i = 1; i <= N; ++i)
    {
        ll curr = dp[0][i];
        for(ll k = 0; k <= 60; ++k)
        {
            if(((1LL << k) & K) != 0)
            {
                curr = dp[k][curr];
            }
        }
        ans.push_back(A[curr]);
    }

    for(auto a : ans) cout << a << " ";
    cout << endl;

    return 0;
}