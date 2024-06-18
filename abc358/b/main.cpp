#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, A;
    cin >> N >> A;
    vector<ll> T(N);
    for(auto &t : T) cin >> t;

    ll last = -1;
    for(ll i = 0; i < N; ++i)
    {
        if(last <= T[i])
        {
            cout << T[i] + A << endl;;
            last = T[i] + A;
        }
        else
        {
            cout << last + A << endl;
            last += A;
        }
    }

    return 0;
}