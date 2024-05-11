#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A, X, Y;

double f(ll n, map<ll, double>& memo)
{
    if(memo.count(n)) return memo[n];
    double tmp1 = f(n / A, memo) + X;
    double tmp2 = 6 * Y;
    for(ll i = 2; i <= 6; ++i) tmp2 += f(n / i, memo);
    double res = min(tmp1, tmp2 / 5.0);
    
    memo[n] = res;
    return memo[n];
}

int main()
{
    cin >> N >> A >> X >> Y;
    map<ll, double> memo;
    memo[0] = 0;
    //for(ll i = 0; i < A; ++i) memo[i] = X;
    cout << fixed << setprecision(15) << f(N, memo) << endl;
    return 0;
}