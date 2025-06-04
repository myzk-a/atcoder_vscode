#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    map<ll, set<ll>> rb, rw, cb, cw;
    set<ll> k_r, k_c;
    for(ll i = 0; i < M; ++i)
    {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        if(c == 'B')
        {
            rb[x].insert(y);
            cb[y].insert(x);
            k_r.insert(x);
            k_c.insert(y);
        }
        else
        {
            rw[x].insert(y);
            cw[y].insert(x);
            k_r.insert(x);
            k_c.insert(y);
        }
    }

    ll min_w = 1LL << 60LL;
    for(auto r : k_r)
    {
        if(rw[r].size() > 0)
        {
            min_w = min(min_w, *rw[r].begin());
        }
        if(rb[r].size() > 0)
        {
            if(min_w <= *rb[r].rbegin())
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}