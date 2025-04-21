#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> A(M), B(M), C(M);
    set<ll> s;
    for(ll i = 0; i < M; ++i)
    {
        cin >> A[i] >> B[i] >> C[i];
        --A[i];
        --B[i];
        s.insert(i);
    }

    vector<ll> q(Q), i(Q), x(Q), y(Q);
    for(ll m = 0; m < Q; ++m)
    {
        cin >> q[m];
        if(q[m] == 1)
        {
            cin >> i[m];
            --i[m];
            s.erase(i[m]);
        }
        else
        {
            cin >> x[m] >> y[m];
            --x[m];
            --y[m];
        }
    }

    const ll INF = 1LL << 60LL;
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    for(ll i = 0; i < N; ++i) dist[i][i] = 0;
    for(ll i = 0; i < M; ++i)
    {
        if(s.count(i) != 0)
        {
            dist[A[i]][B[i]] = C[i];
            dist[B[i]][A[i]] = C[i];
        }
    }

    for(ll k = 0; k < N; ++k)
    {
        for(ll i = 0; i < N; ++i)
        {
            for(ll j = 0; j < N; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<ll> ans;

    for(ll m = Q - 1; m >= 0; --m)
    {
        if(q[m] == 1)
        {
            ll a = A[i[m]];
            ll b = B[i[m]];
            ll c = C[i[m]];
            for(ll j = 0; j < N; ++j)
            {
                for(ll k = 0; k < N; ++k)
                {
                    dist[j][k] = min(dist[j][k], dist[j][a] + c + dist[b][k]);
                    dist[j][k] = min(dist[j][k], dist[j][b] + c + dist[a][k]);
                }
            }
        }
        else
        {
            if(dist[x[m]][y[m]] == INF) ans.push_back(-1);
            else ans.push_back(dist[x[m]][y[m]]);
        }
    }

    reverse(ans.begin(), ans.end());
    for(auto a : ans) cout << a << endl;

    return 0;
}