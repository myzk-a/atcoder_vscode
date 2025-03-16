#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A[101][101][101] = {0};
ll S[101][101][101] = {0};

void init() 
{
    for(ll i = 0; i <= 100; ++i)
    {
        for(ll j = 0; j <= 100; ++j)
        {
            for(ll k = 0; k <= 100; ++k)
            {
                A[i][j][k] = 0;
                S[i][j][k] = 0;
            }
        }
    }
}

int main()
{
    init();
    ll N;
    cin >> N;
    for(ll i = 1; i <= N; ++i)
    {
        for(ll j = 1; j <= N; ++j)
        {
            for(ll k = 1; k <= N; ++k) cin >> A[i][j][k];
        }
    }

    for(ll i = 1; i <= N; ++i)
    {
        for(ll j = 1; j <= N; ++j)
        {
            for(ll k = 1; k <= N; ++k) S[i][j][k] = S[i][j][k - 1] + A[i][j][k];
        }
        for(ll k = 1; k <= N; ++k)
        {
            for(ll j = 1; j <= N; ++j) S[i][j][k] += S[i][j - 1][k];
        }
    }

    ll Q;
    cin >> Q;
    for(ll q = 0; q < Q; ++q)
    {
        ll lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        ll ans = 0;
        for(ll i = lx; i <= rx; ++i)
        {
            ll tmp = S[i][ry][rz] - S[i][ry][lz - 1] - S[i][ly - 1][rz] + S[i][ly - 1][lz - 1]; 
            ans += tmp;
        }
        cout << ans << endl;
    }

    return 0;
}