#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> C(M);
    vector<char> R(M);
    vector<vector<ll>> A(M, vector<ll>(N));
    for(ll i = 0; i < M; ++i)
    {
        cin >> C[i];
        for(ll j = 0; j < C[i]; ++j)
        {
            cin >> A[i][j];
            --A[i][j];
        }
        cin >> R[i];
    }

    ll ans = 0;

    for(ll mask = 0; mask < (1LL << N); ++mask)
    {
        bool f = true;
        for(ll i = 0; i < M; ++i)
        {
            ll cnt = 0;
            for(ll j = 0; j < C[i]; ++j)
            {
                if((mask & (1LL << A[i][j])) != 0) ++cnt;
            }
            if((cnt >= K && R[i] == 'x') || (cnt < K && R[i] == 'o'))
            {
                f = false;
                break;
            }
        }
        if(f) ++ans;
    }

    cout << ans << endl;
    return 0;
}