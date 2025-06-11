#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

struct State
{
    ll h;
    ll w;
    ll to;
    State(ll h, ll w, ll to) : h(h), w(w), to(to) {};
};


int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(auto &s : S) cin >> s;

    ll sh;
    ll sw;
    ll gh;
    ll gw;

    for(ll i = 0; i < H; ++i)
    {
        for(ll j = 0; j < W; ++j)
        {
            if(S[i][j] == 'S')
            {
                sh = i;
                sw = j;
            }
            if(S[i][j] == 'G')
            {
                gh = i;
                gw = j;
            }
        }
    }

    vector<vector<ll>> dist1(H, vector<ll>(W, INF));
    vector<vector<ll>> dist2(H, vector<ll>(W, INF));

    queue<State> que;
    ll dx[2][2] = {{1, -1}, {0, 0}};
    ll dy[2][2] = {{0, 0}, {1, -1}};

    dist1[sh][sw] = 0;
    dist2[sh][sw] = 0;
    que.push(State(sh, sw, 0));
    que.push(State(sh, sw, 1));

    while (!que.empty())
    {
        auto h = que.front().h;
        auto w = que.front().w;
        auto to = que.front().to;
        que.pop();
        for(ll i = 0; i < 2; ++i)
        {
            ll nh = h + dx[to][i];
            ll nw = w + dy[to][i];
            if(nh < 0 || H <= nh || nw < 0 || W <= nw) continue;
            if(S[nh][nw] == '#') continue;
            if(to == 0)
            {
                if(dist2[nh][nw] != INF) continue;;
                dist2[nh][nw] = dist1[h][w] + 1;
                que.push(State(nh, nw, 1));
            }
            else
            {
                if(dist1[nh][nw] != INF) continue;
                dist1[nh][nw] = dist2[h][w] + 1;
                que.push(State(nh, nw, 0));
            }
        }
    }

    ll ans = min(dist1[gh][gw], dist2[gh][gw]);
    if(ans == INF) ans = -1;
    cout << ans << endl;

    return 0;
}