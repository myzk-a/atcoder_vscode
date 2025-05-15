#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

int main()
{
    ll H, W, D;
    cin >> H >> W >> D;
    vector<string> S(H);
    for(auto &s : S) cin >> s;

    ll dr[] = {-1, 1, 0, 0};
    ll dc[] = {0, 0, -1, 1};

    // vector<vector<bool>> check(H, vector<bool>(W, false));
    vector<vector<ll>> dist(H, vector<ll>(W, -1));
    queue<pair<ll, ll>> que;
    for(ll i = 0; i < H; ++i)
    {
        for(ll j = 0; j < W; ++j)
        {
            if(S[i][j] != 'H') continue;
            que.push({i, j});
            dist[i][j] = 0;
        }
    }

    while(!que.empty())
    {
        ll r = que.front().first;
        ll c = que.front().second;
        que.pop();
        for(ll d = 0; d < 4; ++d)
        {
            ll nr = r + dr[d];
            ll nc = c + dc[d];
            if(nr < 0 || H <= nr || nc < 0 || W <= nc) continue;
            if(S[nr][nc] == '#') continue;
            if(dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            que.push({nr, nc});
        }
    }

    ll ans = 0;
    for(ll i = 0; i < H; ++i)
    {
        for(ll j = 0; j < W; ++j)
        {
            if(dist[i][j] == -1) continue;
            if(dist[i][j] > D) continue;
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}