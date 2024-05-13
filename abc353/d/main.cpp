#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;

int main()
{
    vector<mint> pow_10;
    mint v = 1;
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
    map<ll, mint> cnt;
    set<ll> key;
    for(auto a : A)
    {
        auto s = to_string(a);
        ll keta = s.size();
        if(cnt.count(keta)) ++cnt[keta];
        else cnt[keta] = 1;
        key.insert(keta);
    }

    vector<mint> sum(N, 0);
    sum[0] = A[0];
    for(ll i = 1; i < N; ++i)
    {
        sum[i] = sum[i-1] + A[i];
    } 
    mint ans = 0;
    for(ll i = 0; i < N; ++i)
    {
        ll a = A[i];
        auto s = to_string(a);
        ll keta = s.size();
        --cnt[keta];
        for(auto k : key)
        {
            ans += cnt[k] * mint(a) * pow_10[k];
        }
        mint tmp = sum[N - 1] - sum[i];
        ans += tmp;
    }

    std::cout << ans.val() << std::endl;
    return 0;
}