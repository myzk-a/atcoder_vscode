#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll a, ll n)
{
    ll res = 1;
    for(ll i = 1; i <= n; ++i) res *= a;
    return res;
}

bool is_sname_num(string s)
{
    for(ll i = 1; i < s.size(); ++i)
    {
        if(s[i] >= s[0]) return false;
    }
    return true;
}

ll solve(ll n)
{
    if(n < 10) return 0;

    string s = to_string(n);
    ll keta = s.size();
    ll res = 0;
    if(is_sname_num(s)) ++ res;
    for(ll k = 2; k <= keta; ++k)
    {
        if(k < keta)
        {
            for(ll i = 1; i <= 9; ++i) 
            {
                res += f(i, k - 1);
            }
        }
        else
        {
            for(ll i = 0; i < s.size(); ++i)
            {
                if(i != 0 && s[i] - '0' >= s[0] - '0')
                {
                    res += f(s[0] - '0', keta - i);
                    return res;
                }
                else
                {
                    for(ll j = 0; j < s[i] - '0'; ++j)
                    {
                        if(j == 0 && i == 0) continue;
                        ll head;
                        if(i == 0)
                        {
                            head = j;
                        }
                        else
                        {
                            head = s[0] - '0';
                        }
                        res += f(head, keta - i - 1);
                    }
                }
            }
        }
    }
    return res;
}


int main()
{
    ll L, R;
    cin >> L >> R;
    auto ans = solve(R) - solve(L - 1);
    cout << ans << endl;
    return 0;
}