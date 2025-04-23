#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

int main()
{
    ll N, M;
    cin >> N >> M;
    Graph g(N + 1);
    for(ll i = 0; i < M; ++i)
    {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        if(b == 0) b = N;
        g[a].push_back(b);
    }

    vector<ll> dist(N + 1, -1);
    dist[0] = 0;
    queue<ll> que;
    que.push(0);
    while (!que.empty())
    {
        auto v = que.front();
        que.pop();
        for(auto nv : g[v])
        {
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    cout << dist[N] << endl;

    return 0;
}