#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for(auto &a : A) cin >> a;

    if(N == M)
    {
        for(ll i = 0; i < N; ++i) cout << 0 << " ";
        cout << endl;
        return 0;
    }

    auto a = A;
    sort(a.begin(), a.end());
    vector<ll> sum(N + 1, 0);
    for(ll i = 0; i < N; ++i) sum[i + 1] = sum[i] + a[i];

    ll remain = K;
    for(auto x : a) remain -= x;

    map<ll, ll> ans;

    for(ll i = 0; i < N; ++i)
    {
        auto f = [&](ll x) -> bool
        {
            ll y = a[i] + x;
            auto r = upper_bound(a.begin(), a.end(), y + 1) - a.begin();
            auto l = N - M;
            if(r < l) return false;
            ll need = (r - l) * (y + 1) - (sum[r] - sum[l]);
            if(l <= i && i < r)
            {
                need += a[i];
                need -= a[l - 1];
            }
            return need > remain - x;
        };

        ll ok = remain + 1;
        ll ng = -1;
        while(abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if(f(mid)) ok = mid;
            else ng = mid;
        }
        if(ok == remain + 1) ok = -1;
        ans[a[i]] = ok;
    }

    for(ll i = 0; i < N; ++i) cout << ans[A[i]] << " ";
    cout << endl;

    return 0;
}