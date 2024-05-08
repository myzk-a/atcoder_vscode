#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

ll dfs(Graph &g, ll v, vector<bool>& check1, vector<bool>& check2)
{
    check1[v] = true;
    check2[v] = true;
    if(g[v].size() == 0) return 1;
    ll res = 1;
    for(auto nv : g[v])
    {
        if(check2[nv]) continue;
        res += dfs(g, nv, check1, check2); 
    }
    return res;
}

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(auto &s : S) cin >> s;
    Graph g(H * W);
    for(ll i = 0; i < H; ++i)
    {
        for(ll j = 0; j < W; ++j)
        {
            if(S[i][j] == '#') continue;
            bool f = true;
            if(i - 1 >= 0 && S[i - 1][j] == '#') f = false;
            if(i + 1 < H && S[i + 1][j] == '#') f = false;
            if(j - 1 >= 0 && S[i][j - 1] == '#') f= false;
            if(j + 1 < W && S[i][j + 1] == '#') f = false;
            if(f)
            {
                ll curr = i * W + j;
                if(i - 1 >= 0) g[curr].push_back((i - 1) * W + j);
                if(i + 1 < H) g[curr].push_back((i + 1) * W + j);
                if(j - 1 >= 0) g[curr].push_back(i * W + j - 1);
                if(j + 1 < W) g[curr].push_back(i * W + j + 1);
            }
        }
    }

    ll ans = -1;
    vector<bool> check1(H * W, false);
    for(ll i = 0; i < H; ++i)
    {
        for(ll j = 0; j < W; ++j)
        {
            if(check1[i * W + j]) continue;
            vector<bool> check2(H * W, false);
            ll res = dfs(g, i * W + j, check1, check2);
            ans = max(ans, res);
        }
    }

    cout << ans << endl;
    return 0;
}