#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x, y, z;
    cin >> n >> x >> y >> z;
    if(x > y) swap(x, y);
    if(x <= z && z <= y) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}