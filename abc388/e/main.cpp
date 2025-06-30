#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool f(ll n, const vector<ll>& A)
{
    ll N = A.size();
    for(ll i = 0; i < n; ++i)
    {
        ll u = A[i];
        ll b = A[N - n + i];
        if(2 * u > b) return false;
    }
    return true;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(auto &a : A) cin >> a;
    
    ll ok = 0;
    ll ng = N / 2 + 1;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if(f(mid, A)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}