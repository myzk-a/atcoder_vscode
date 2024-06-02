#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, H, W;
    cin >> N >> H >> W;
    vector<pair<ll, ll>> ab(N);
    for(ll i = 0; i < N; ++i) cin >> ab[i].first >> ab[i].second;

    auto dfs = [&](auto dfs, vector<string> s, vector<bool> used) -> bool
    {
        ll si = -1;
        ll sj = -1;
        for(ll i = 0; i < H; ++i)
        {
            for(ll j = 0; j < W; ++j)
            {
                if(s[i][j] == '.' && si == -1)
                {
                    si = i;
                    sj = j;
                }
            }
        }
        if(si == -1)
        {
            cout << "Yes" << endl;
            //for(ll i = 0; i < H; ++i) cerr << s[i] << endl;
            return true;
        }


        for(ll i = 0; i < N; ++i)
        {
            if(used[i]) continue;
            ll a = ab[i].first;
            ll b = ab[i].second;
            for(ll j = 0; j < 2; ++j)
            {
                swap(a, b);
                if(si + a > H || sj + b > W) continue;

                bool ok = true;
                for(ll ai = 0; ai < a; ++ai)
                {
                    for(ll bi = 0; bi < b; ++bi)
                    {
                        if(s[si + ai][sj + bi] != '.') ok = false;
                    }
                }
                if(!ok) continue;

                auto nused = used;
                nused[i] = true;
                auto ns = s;
                for(ll ai = 0; ai < a; ++ai)
                {
                    for(ll bi = 0; bi < b; ++bi)
                    {
                        ns[si + ai][sj + bi] = '#';
                 }
                }
                if(dfs(dfs, ns, nused)) return true;
            }
        }
        return false;
    };

    if(!dfs(dfs, vector<string>(H, string(W, '.')), vector<bool>(N, false)))
    {
        cout << "No" << endl;
    }

    return 0;
}