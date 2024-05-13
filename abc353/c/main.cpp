#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e8;


int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(auto &a : A) cin >> a;
    sort(A.begin(), A.end());
    vector<ll> sum(N, 0);
    sum[0] = A[0];
    for(ll i = 1; i < N; ++i) sum[i] = sum[i-1] + A[i];

    ll ans = 0;
    for(ll i = 0; i < N - 1; ++i)
    {
        ll a = A[i];
        ans += sum.back() - sum[i];
        ans += A[i] * (N - i - 1);
        ll d = M - a;
        auto idx = lower_bound(A.begin() + i + 1, A.end(), d) - A.begin();
        if(idx == N) continue;
        ans -= M * (N - idx);
    }

    cout << ans << endl;

    return 0;
}