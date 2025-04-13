#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for(ll i = 0; i < N; ++i) cin >> A[i] >> P[i] >> B[i] >> Q[i];

    ll ok = 0;
    ll ng = 1LL << 30LL;

    auto g = [&](ll i, ll m) -> ll
    {
        ll res = 1LL << 30LL;
        for(ll k = 0; k <= B[i]; ++k)
        {
            ll tmp = P[i] * k;
            ll remain = m - A[i] * k;
            if(remain > 0)
            {
                ll l = remain / B[i];
                if(remain % B[i] != 0) ++l;
                tmp += l * Q[i];
            }
            res = min(res, tmp);
        }

        for(ll k = 0; k <= A[i]; ++k)
        {
            ll tmp = Q[i] * k;
            ll remain = m - B[i] * k;
            if(remain > 0)
            {
                ll l = remain / A[i];
                if(remain % A[i] != 0) ++l;
                tmp += l * P[i];
            }
            res = min(res, tmp);
        }
        return res;
    };

    auto f = [&](ll m) -> bool
    {
        ll sum = 0;
        for(ll i = 0; i < N; ++i)
        {
            sum += g(i, m);
        }
        return sum <= X;
    };

    while(abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}