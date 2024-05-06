#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i];
    vector<ll> B(N + 1);
    for(ll i = 1; i <= N; ++i) B[A[i]] = i;

    vector<pair<ll, ll>> ans;

    for(ll i = 1; i <= N; ++i)
    {
        if(A[i] == i) continue;
        ans.push_back({i, B[i]});
        ll tmp1 = A[i];
        ll tmp2 = B[i];
        swap(A[i], A[B[i]]);
        B[i] = i;
        B[tmp1] = tmp2;
    }

    cout << ans.size() << endl;
    for(auto a: ans) cout << a.first << " " << a.second << endl;

    return 0;
}