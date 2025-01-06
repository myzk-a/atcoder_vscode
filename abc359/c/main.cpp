#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    if(sx % 2 != sy % 2) --sx;
    if(tx % 2 != ty % 2) --tx;

    tx -= sx;
    ty -= sy;

    tx = abs(tx);
    ty = abs(ty);

    ll ans = ty;
    if(tx > ty)
    {
        ans += (tx - ty) / 2;
    }

    cout << ans << endl;

    return 0;
}