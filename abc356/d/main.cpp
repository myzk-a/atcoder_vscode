#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll MOD = 998244353LL;

map<pair<ll, ll>, ll> memo;

ll f(ll n, ll m)
{
    if(n == 0) return 0;
    if(n == 1) return __popcount(m & 1) % MOD;
    if(memo.count({n, m})) return memo[{n, m}];

    ll k = -1;
    for(ll i = 60; i >= 0; --i)
    {
        if((n & (1LL << i)) != 0)
        {
            k = i;
            break;
        }
    }

    ll res = f((1LL << k) - 1, m);

    if((m & (1LL << k)) != 0)
    {
        ll tmp = n - (1LL << k) + 1;
        tmp %= MOD;
        res += tmp;
        res %= MOD;
    }

    ll tmp = f(n - (1LL << k), m);
    tmp %= MOD;
    res += tmp;
    res %= MOD;

    return memo[{n, m}] = res;
}

int main()
{
    ll N, M;
    cin >> N >> M;

    ll ans = f(N, M);
    cout << ans << endl;

    return 0;
}