#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> H(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> H[i];
    for(ll i = 2; i <= N; ++i)
    {
        if(H[i] > H[1])
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << - 1 << endl;
    return 0;
}