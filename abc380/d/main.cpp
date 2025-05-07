#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll a, ll n)
{
    ll b = n;
    while(b < a)
    {
        b *= 2;
    }

    return a - b / 2;
}

int main()
{
    string S;
    ll Q;
    cin >> S >> Q;

    ll n = S.size();

    for(ll i = 0; i < Q; ++i)
    {
        ll k;
        cin >> k;

        ll cnt = 0;
        while(k > n)
        {
            k = f(k, n);
            ++cnt;
        }

        auto ans = S[k - 1];
        if(cnt % 2)
        {
            if(islower(ans)) ans -= 32;
            else ans += 32;
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}