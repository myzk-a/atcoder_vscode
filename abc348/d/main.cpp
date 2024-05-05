#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> A(H);
    for(auto &a : A) cin >> a;
    ll N;
    cin >> N;
    vector<vector<ll>> R(H, vector<ll>(W, 0));
    map<pair<ll, ll>, ll> m;
    for(ll i = 0; i < N; ++i)
    {
        ll r, c, e;
        cin >> r >> c >> e;
        --r;
        --c;
        R[r][c] = e;
        m[{r, c}] = i;
    }

    ll si, sj, ti, tj;
    for(ll i = 0; i < H; ++i)
    {
        for(ll j = 0; j < W; ++j)
        {
            if(A[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            if(A[i][j] == 'T')
            {
                ti = i;
                tj = j;
            }
        }
    }

    vector<bool> f(N, false);
    vector<vector<ll>> dist(H, vector<ll>(W, -1));
    priority_queue<pair<ll, pair<pair<ll, ll>, vector<bool>>>> que;
    if(R[si][sj] > 0)
    {
        f[m[{si, sj}]] = true;
        dist[si][sj] = R[si][sj];
        que.push({dist[si][sj], {{si, sj}, f}});
    }

    ll dx[] = {0, 1, 0, -1};
    ll dy[] = {1, 0, -1, 0};

    while(!que.empty())
    {
        ll d = que.top().first;
        ll i = que.top().second.first.first;
        ll j = que.top().second.first.second;
        vector<bool> _f = que.top().second.second;
        if(i == ti && j == tj)
        {
            cout << "Yes" << endl;
            return 0;
        }
        que.pop();
        if(d < dist[i][j]) continue;
        if(d == 0) continue;
        for(ll k = 0; k < 4; ++k)
        {
            ll ni = i + dx[k];
            ll nj = j + dy[k];
            if(ni < 0 || H <= ni || nj < 0 || W <= nj) continue;
            if(A[ni][nj] == '#') continue;
            if(R[ni][nj] > d - 1 && !_f[m[{ni, nj}]] )
            {
                if(R[ni][nj] > dist[ni][nj])
                {
                    dist[ni][nj] = R[ni][nj];
                    _f[m[{ni, nj}]] = true;
                    que.push({dist[ni][nj], {{ni, nj}, _f}});
                }
            }
            else
            {
                if(d - 1 > dist[ni][nj])
                {
                    dist[ni][nj] = d - 1;
                    que.push({d - 1, {{ni, nj}, _f}});
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}