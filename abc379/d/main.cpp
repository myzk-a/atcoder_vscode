#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll Q;
    cin >> Q;
    queue<ll> que;
    ll now = 0;
    for(ll i = 0; i < Q; ++i)
    {
        ll q;
        cin >> q;
        if(q == 1)
        {
            que.push(now);
        }
        else if(q == 2)
        {
            ll t;
            cin >> t;
            now += t;
        }
        else
        {
            ll h;
            cin >> h;
            ll ans = 0;
            while (!que.empty())
            {
                if(now - que.front() >= h)
                {
                    ++ans;
                    que.pop();
                }
                else
                {
                    break;
                }
            }
            
            cout << ans << endl;
        }
    }
    return 0;
}