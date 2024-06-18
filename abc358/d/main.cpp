#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll ans = 0;
    ll ai = 0;
    for(ll bi = 0; bi < M; ++bi)
    {
        while(ai < N)
        {
            if(B[bi] <= A[ai])
            {
                break;
            }
            ++ai;
        }
        if(ai >= N)
        {
            cout << -1 << endl;
            return 0;
        }
        ans += A[ai];
        ++ai;
    }

    cout << ans << endl;

    return 0;
}