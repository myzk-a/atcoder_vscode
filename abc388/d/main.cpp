#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i];
    vector<ll> C(N + 2, 0);
    for(ll i = 1; i <= N; ++i)
    {
        C[i] += C[i - 1];
        A[i] += C[i];
        ll tmp = min(N - i, A[i]);
        A[i] -= tmp;
        ++C[i + 1];
        --C[i + 1 + tmp];
    }
    for(ll i = 1; i <= N; ++i) cout << A[i] << " ";
    cout << endl;
    return 0;
}