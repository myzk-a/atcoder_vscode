#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(auto &s : S) cin >> s;
    ll ans = 1LL << 60LL;

    for(ll mask = 0; mask < (1LL << N); ++mask)
    {
        vector<bool> checked(M, false);
        ll cnt = 0;
        for(ll i = 0; i < N; ++i)
        {
            if((mask & (1LL << i) ) != 0)
            {
                ++cnt;
                for(ll j = 0; j < S[i].size(); ++j)
                {
                    if(S[i][j] == 'o')
                    {
                        checked[j] = true;
                    }
                }
            }
        }
        bool f = true;
        for(ll j = 0; j < M; ++j)
        {
            if(!checked[j]) f = false;
        }
        if(f) ans = min(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}