#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    ll sum = 0;
    for(ll i = 0; i < N - 1; ++i)
    {
        ll a;
        cin >> a;
        sum += a;
    }

    cout << -sum << endl;
    return 0;
}