#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(auto &a : A) cin >> a;

    ll ans = 0;
    ll rest = K;
    for(auto a : A)
    {
        if(a <= rest)
        {
            rest -= a;
        }
        else
        {
            ++ans;
            rest = K - a;
        }
    }

    if(rest < K) ++ans;

    cout << ans << endl;
    return 0;
}