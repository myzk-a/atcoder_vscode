#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

int main()
{
    ll N, M;
    cin >> N >> M;

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, INF));
    vector<pair<ll, ll>> edges(M + 1);
    vector<ll> ts(M + 1);
    for(ll i = 1; i <= N; ++i) dp[i][i] = 0;
    for(ll i = 1; i <= M; ++i)
    {
        ll u, v, t;
        cin >> u >> v >> t;
        dp[u][v] = min(dp[u][v], t);
        dp[v][u] = dp[u][v];
        edges[i] = {u, v};
        ts[i] = t;
    }
    for(ll k = 1; k <= N; ++k)
    {
        for(ll i = 1; i <= N; ++i)
        {
            for(ll j = 1; j <= N; ++j)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    ll Q;
    cin >> Q;
    for(ll q = 0; q < Q; ++q)
    {
        ll K;
        cin >> K;
        ll ans = INF;
        vector<ll> es;
        for(ll k = 0; k < K; ++k)
        {
            ll e;
            cin >> e;
            es.push_back(e);
        }
        sort(es.begin(), es.end());

        do
        {
            for(ll bit = 0; bit < (1LL << es.size()); ++bit)
            {
                ll tmp = 0;
                ll curr = 1;
                for(ll i = 0; i < es.size(); ++i)
                {
                    auto edge = edges[es[i]];
                    tmp += ts[es[i]];
                    if((bit & (1LL << i)) != 0)
                    {
                        tmp += dp[curr][edge.first];
                        curr = edges[es[i]].second;
                    }
                    else
                    {
                        tmp += dp[curr][edge.second];
                        curr = edges[es[i]].first;
                    }
                }
                tmp += dp[curr][N];
                ans = min(ans, tmp);
            }
        } while (next_permutation(es.begin(), es.end()));

        cout << ans << endl;
    }

    return 0;
}