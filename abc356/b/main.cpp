#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M);
    vector<ll> B(M, 0);
    for(ll i = 0; i < M; ++i) cin >> A[i];
    for(ll i = 0; i < N; ++i)
    {
        for(ll j = 0; j < M; ++j)
        {
            ll x;
            cin >> x;
            B[j] += x;
        }
    }

    for(ll i = 0; i < M; ++i)
    {
        if(A[i] > B[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}