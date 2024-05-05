#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    map<ll, ll> m;
    for(ll i = 0; i < N; ++i)
    {
        ll a, c;
        cin >> a >> c;
        if(m.count(c))
        {
            m[c] = min(m[c], a);
        }
        else
        {
            m[c] = a;
        }
    }

    ll ans = -1;
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        ans = max(ans, it->second);
    }

    cout << ans << endl;
    return 0;
}