#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    for(ll i = 1; i <= N; ++i)
    {
        if(i % 3 != 0) cout << "o";
        else cout << "x";
    }
    cout << endl;
    return 0;
}