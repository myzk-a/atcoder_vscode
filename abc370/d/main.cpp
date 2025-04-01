#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll H, W, Q;
    cin >> H >> W >> Q;
    set<ll> r, c;
    for(ll i = 1; i <= W; ++i) r.insert(i);
    for(ll i = 1; i <= H; ++i) c.insert(i);
    vector<set<ll>> row(H + 1), col(W + 1);
    for(ll i = 1; i <= H; ++i) row[i] = r;
    for(ll i = 1; i <= W; ++i) col[i] = c;

    for(ll q = 0; q < Q; ++q)
    {
        ll r, c;
        cin >> r >> c;
        ll c1 = -1;
        ll c2 = -1;
        auto iter1 = row[r].lower_bound(c);
        if(iter1 != row[r].end())
        {
            c1 = *iter1;
        }
        if(c1 != c && iter1 != row[r].begin())
        {
            --iter1;
            c2 = *iter1;
            row[r].erase(c2);
        }
        if(c1 != -1)
        {
            row[r].erase(c1);
        }

        ll r1 = -1;
        ll r2 = -1;
        auto iter2 = col[c].lower_bound(r);
        if(iter2 != col[c].end())
        {
            r1 = *iter2;
        }
        if(r1 != r && iter2 != col[c].begin())
        {
            --iter2;
            r2 = *iter2;
            col[c].erase(r2);
        }
        if(r1 != -1)
        {
            col[c].erase(r1);
        }

        if(r1 != -1)
        {
            row[r1].erase(c);
        }
        if(r2 != -1)
        {
            row[r2].erase(c);
        }

        if(c1 != -1)
        {
            col[c1].erase(r);
        }
        if(c2 != -1)
        {
            col[c2].erase(r);
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= H; ++i) ans += row[i].size();
    cout << ans << endl;
    return 0;
}