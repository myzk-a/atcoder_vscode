#include <bits/stdc++.h>
using namespace std;
using ll = int;

int main()
{
    ll H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for(ll i = 0; i < H; ++i) cin >> S[i];

    ll di[] = {1, -1, 0, 0};
    ll dj[] = {0, 0, 1, -1};
    vector<vector<bool>> checked(H, vector<bool>(W, false));

    auto f = [&](auto f, ll i, ll j, ll k) -> ll
    {
        checked[i][j] = true;
        if(k == K) 
        {
            checked[i][j] = false;
            return 1;
        }

        ll res = 0;
        for(ll d = 0; d < 4; ++d)
        {
            ll ni = i + di[d];
            ll nj = j + dj[d];
            if(ni < 0 || H <= ni || nj < 0 || W <= nj ) continue;
            if(S[ni][nj] == '#') continue;
            if(checked[ni][nj]) continue;
            res += f(f, ni, nj, k + 1);
        }
        checked[i][j] = false;
        return res;
    };

    long long ans = 0;
    for(ll i = 0; i < H; ++i)
    {
        for(ll j = 0; j < W; ++j)
        {
            if(S[i][j] == '#') continue;
            ans += f(f, i, j, 0);
        }
    }

    cout << ans << endl;

    return 0;
}