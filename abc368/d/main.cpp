#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

int main()
{
    ll N, K;
    cin >> N >> K;
    Graph g(N);
    for(ll i = 0; i < N - 1; ++i)
    {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    set<ll> vs;
    for(ll i = 0; i < K; ++i)
    {
        ll v;
        cin >> v;
        --v;
        vs.insert(v);
    }

    ll ans = 0;
    auto f = [&](auto f, ll v, ll p) -> bool
    {
        bool flag = false;
        if(vs.count(v))
        {
            flag = true;
        }
        for(auto nv : g[v])
        {
            if(nv == p) continue;
            if(f(f, nv, v))
            {
                flag = true;
            }
        }
        if(flag) ++ans;
        return flag;
    };

    f(f, *vs.begin(), -1);

    cout << ans << endl;

    return 0;
}