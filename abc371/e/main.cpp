#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i];

    ll ans = 0;
    set<ll> s;
    for(ll i = 1; i <= N; ++i) s.insert(A[i]);
    ans = N * (N + 1) / 2 * s.size();
 
    map<ll, ll> m;
    for(ll i = 1; i <= N; ++i)
    {
        ll n = i - m[A[i]] - 1;
        ll tmp = n * (n + 1) / 2;
        ans -= tmp;
        m[A[i]] = i;
    }

    for(auto v : s)
    {
        ll n = N + 1 - m[v] - 1;
        ll tmp = n * (n + 1) / 2;
        ans -= tmp;
    }

    cout << ans << endl;

    return 0;
}