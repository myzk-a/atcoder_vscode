#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x, ll y)
{
  ll rx = x % 4;
  x -= rx;
  ll ry = y % 2;
  y -= ry;
  ll res = 0;
  res += x * y;
  if(ry)
  {
    res += x;
  }
  if(rx >= 1)
  {
    res += y * 3 / 2;
    if(ry)
    {
      res += 2;
    }
  }
  if(rx >= 2)
  {
    res += y * 3 / 2;
    if(ry)
    {
      res += 1;
    }
  }
  if(rx >= 3)
  {
    res += y / 2;
  }
  return res;
}

int main()
{
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  a += 1e9;
  b += 1e9;
  c += 1e9;
  d += 1e9;

  ll ans = f(c, d) - f(a, d) - f(c, b) + f(a, b);
  cout << ans << endl;

  return 0;
}