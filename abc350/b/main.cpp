#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, Q;
    cin >> N >> Q;
    vector<bool> f(N + 1, true);
    for(ll i = 0; i < Q; ++i)
    {
        ll t;
        cin >> t;
        f[t] = !f[t];
    }

    ll ans = 0;
    for(ll i = 1; i <= N; ++i)
    {
        if(f[i]) ++ans;
    }

    cout << ans << endl;

    return 0;
}