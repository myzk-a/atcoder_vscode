#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 998244353LL;

int main()
{
    vector<ll> pow_10;
    ll v = 1;
    pow_10.push_back(v);
    for(ll i = 1; i <= 10; ++i)
    {
        v *= 10;
        pow_10.push_back(v);
    }

    ll N;
    cin >> N;
    vector<ll> A(N);
    for(auto &a : A) cin >> a;
    map<ll, ll> cnt;
    set<ll> key;
    for(auto a : A)
    {
        auto s = to_string(a);
        ll keta = s.size();
        if(cnt.count(keta)) ++cnt[keta];
        else cnt[keta] = 1;
        key.insert(keta);
    }

    vector<ll> sum(N, 0);
    sum[0] = A[0];
    for(ll i = 1; i < N; ++i)
    {
        sum[i] = sum[i-1] + A[i];
        sum[i] %= M;
    } 
    ll ans = 0;
    for(ll i = 0; i < N; ++i)
    {
        ll a = A[i];
        auto s = to_string(a);
        ll keta = s.size();
        --cnt[keta];
        for(auto k : key)
        {
            ans += (((cnt[k] * a) % M) * (pow_10[k] % M )) % M;
            ans %= M;
        }
        ll tmp = sum[N - 1] - sum[i];
        if(tmp < 0) tmp += M;
        tmp %= M;
        ans += tmp;
        ans %= M;
    }

    ans %= M;
    std::cout << ans << std::endl;
    return 0;
}