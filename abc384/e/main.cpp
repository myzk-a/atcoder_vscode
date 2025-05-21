#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll H, W, X, P, Q;
    cin >> H >> W >> X >> P >> Q;
    --P;
    --Q;
    vector<vector<ll>> S(H, vector<ll>(W));
    for(ll i = 0; i < H; ++i)
    {
        for(ll j = 0; j < W; ++j) cin >> S[i][j];
    }

    ll di[] = {1, -1, 0, 0};
    ll dj[] = {0, 0, 1, -1};

    ll ans = S[P][Q];
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> que;
    vector<vector<bool>> check(H, vector<bool>(W, false));
    check[P][Q] = true;

    for(ll i = 0; i < 4; ++i)
    {
        ll ni = P + di[i];
        ll nj = Q + dj[i];
        if(ni < 0 || H <= ni || nj < 0 || W <= nj) continue;
        que.push({S[ni][nj], {ni, nj}});
    }

    while(!que.empty())
    {
        auto p = que.top().first;
        auto ci = que.top().second.first;
        auto cj = que.top().second.second;
        que.pop();
        if(check[ci][cj]) continue;

        if(p < (ans + X - 1) / X)
        {
            ans += p;
            check[ci][cj] = true;
            for(ll i = 0; i < 4; ++i)
            {
                ll ni = ci + di[i];
                ll nj = cj + dj[i];
                if(ni < 0 || H <= ni || nj < 0 || W <= nj) continue;
                if(check[ni][nj]) continue;
                que.push({S[ni][nj], {ni, nj}});
            }
        }
        else
        {
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}