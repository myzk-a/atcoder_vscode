#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    list<ll> ls;
    map<ll, list<ll>::iterator> m;
    for(ll i = 0; i < N; ++i)
    {
        ll a;
        cin >> a;
        ls.insert(ls.end(), a);
        m[a] = prev(ls.end());
    }

    ll Q;
    cin >> Q;
    for(ll i = 0; i < Q; ++i)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            ll x, y;
            cin >> x >> y;
            auto it = m[x];
            ls.insert(next(it), y);
            m[y] = next(it);
        }
        else
        {
            ll x;
            cin >> x;
            auto it = m[x];
            m.erase(x);
            ls.erase(it);
        }
    }

    for(auto v : ls) cout << v << " ";
    cout << endl;

    return 0;
}