#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; ++i) cin >> A[i] >> B[i];

    ll sum = 0;
    for(auto a: A) sum += a;

    ll ans = -1;
    for(ll i = 0; i < N; ++i)
    {
        ans = max(ans, sum - A[i] + B[i]);
    }

    cout << ans << endl;
    return 0;
}