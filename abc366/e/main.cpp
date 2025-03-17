#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> f(ll N, ll D, vector<ll> V, vector<ll> S)
{
    vector<ll> res;
    for(ll x = V[0] - D; x <= V.back() + D; ++x)
    {
        auto iter = lower_bound(V.begin(), V.end(), x);
        ll sum = 0;
        if(iter == V.end())
        {
            sum = x * V.size() - S.back();
        }
        else
        {
            auto idx = iter - V.begin();
            sum = x * idx - S[idx] - x * (N - idx) + (S.back() - S[idx]);
        }
        if(sum <= D) res.push_back(sum);
    }

    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll N, D;
    cin >> N >> D;
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N; ++i) cin >> X[i] >> Y[i];
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    vector<ll> SX(N + 1, 0), SY(N + 1, 0);
    for(ll i = 0; i < N; ++i)
    {
        SX[i + 1] = SX[i] + X[i];
        SY[i + 1] = SY[i] + Y[i];
    }

    auto dxs = f(N, D, X, SX);
    auto dys = f(N, D, Y, SY);

    ll ans = 0;
    for(auto dx : dxs)
    {
        auto iter = upper_bound(dys.begin(), dys.end(), D - dx) - dys.begin();
        ans += iter;
    }

    cout << ans << endl;

    return 0;
}