#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<vector<char>> A(N + 1, vector<char>(N + 1));
    for(ll i = 1; i <= N; ++i)
    {
        for(ll j = 1; j <= N; ++j) cin >> A[i][j];
    }

    auto ans = A;
    for(ll i = 1; i <= N; ++i)
    {
        for(ll j = 1; j <= N; ++j)
        {
            ll d = i;
            d = min(d, N - i + 1);
            d = min(d, j);
            d = min(d, N - j + 1);
            d %= 4;
            if(d == 1)
            {
                ans[i][j] = A[N + 1 - j][i];
            }
            else if(d == 2)
            {
                ans[i][j] = A[N + 1 - i][N + 1 - j];
            }
            else if(d == 3)
            {
                ans[i][j] = A[j][N + 1 - i];
            }
        }
    }

    for(ll i = 1; i <= N; ++i)
    {
        for(ll j = 1; j <= N; ++j) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}