#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll a, ll n)
{
    ll res = (2 * a - n + 1) * n / 2;
    return res;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M), A(M);
    for(auto &x : X) cin >> x;
    for(auto &a : A) cin >> a;
    vector<pair<ll, ll>> p;
    for(ll i = 0; i < M; ++i) p.push_back({X[i], A[i]});
    sort(p.begin(), p.end());

    if(p[0].first != 1)
    {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    for(ll i = 0; i < M - 1; ++i)
    {
        ll curr = p[i].first;
        ll next = p[i + 1].first;
        if(p[i].second < next - curr)
        {
            cout << -1 << endl;
            return 0;
        }
        p[i + 1].second += p[i].second - (next - curr); 
        ans += f(p[i].second - 1, next - curr);
    }

    if(p.back().first == N)
    {
        if(p.back().second != 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    else
    {
        if(p.back().second != N - p.back().first + 1)
        {
            cout << -1 << endl;
            return 0;
        }
        ans += f(p.back().second - 1, N - p.back().first);
    }

    cout << ans << endl;
    return 0;
}