#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<ll> A(9), B(8);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    ll sum_a = 0;
    for(auto a: A) sum_a += a;

    ll sum_b = 0;
    for(auto b: B) sum_b += b;

    cout << sum_a - sum_b + 1 << endl;

    return 0;
}