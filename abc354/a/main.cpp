#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll H;
    cin >> H;
    ll ans = 1;
    ll h = 1;
    while(h <= H)
    {
        h += (1 << ans);
        ++ans;
    }
    cout << ans << endl;
    return 0;
}