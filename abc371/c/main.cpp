#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

int main()
{
    ll N, MG;
    cin >> N >> MG;
    vector<set<ll>> G(N + 1), H(N + 1);
    for(ll i = 0; i < MG; ++i)
    {
        ll u, v;
        cin >> u >> v;
        G[u].insert(v);
        // G[v].insert(u);
    }
    ll MH;
    cin >> MH;
    for(ll i = 0; i < MH; ++i)
    {
        ll u, v;
        cin >> u >> v;
        H[u].insert(v);
        H[v].insert(u);
    }

    vector<vector<ll>> A(N + 1, vector<ll>(N + 1, 0));
    for(ll i = 1; i <= N - 1; ++i)
    {
        for(ll j = i + 1; j <= N; ++j) cin >> A[i][j];
    }

    ll ans = INF;
    vector<ll> v;
    for(ll i = 1; i <= N; ++i) v.push_back(i);
    do
    {
        ll tmp = 0;
        for(ll i = 1; i <= N; ++i)
        {
            for(ll j = i + 1; j <= N; ++j)
            {
                ll cnt1 = G[i].count(j);
                ll cnt2 = H[v[i - 1]].count(v[j - 1]);
                if(cnt1 != cnt2)
                {
                    tmp += A[v[i - 1]][v[j - 1]];
                    tmp += A[v[j - 1]][v[i - 1]];
                }
            }
        }
        ans = min(ans, tmp);

    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
}