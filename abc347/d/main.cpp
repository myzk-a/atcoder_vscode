#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main()
{
    ll a, b, C;
    cin >> a >> b >> C;

    bool f = false;
    if(a < b)
    {
        swap(a, b);
        f = true;
    } 

    vector<ll> bit_c(60, 0);
    ll cnt = 0;
    for(ll i = 0; i < 60; ++i)
    {
        if((C & (1LL << i)) != 0)
        {
            bit_c[i] = 1;
            ++cnt;
        }
    }

    ll d = a - b;
    if(cnt < d || (cnt - d) % 2 || cnt > a + b || 60 - cnt + (cnt - d) / 2 + d < a)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> bit_a(60, 0);
    vector<ll> bit_b(60, 0);
    ll cnt_a = 0;
    for(ll i = 0; i < 60; ++i)
    {
        if(bit_c[i])
        {
            if(cnt_a < (cnt - d) / 2 + d)
            {
                bit_a[i] = 1;
                ++cnt_a;
            }
            else
            {
                bit_b[i] = 1;
            }
        }
    }

    for(ll i = 0; i < 60; ++i)
    {
        if(bit_c[i] == 0)
        {
            if(cnt_a < a)
            {
                bit_a[i] = 1;
                bit_b[i] = 1;
                ++cnt_a;
            }
        }
    }

    ll ans_a = 0;
    ll ans_b = 0;

    for(ll i = 0; i < 60; ++i)
    {
        if(bit_a[i]) ans_a += (1LL << i);
        if(bit_b[i]) ans_b += (1LL << i);
    }

    cnt_a = 0;
    ll cnt_b = 0;
    for(ll i = 0; i < 60; ++i)
    {
        if(bit_a[i]) ++cnt_a;
        if(bit_b[i]) ++cnt_b;
    }

    assert(a == cnt_a);
    assert(b == cnt_b);
    assert(C == ans_a ^ ans_b);
    if(f) swap(ans_a, ans_b);
    cout << ans_a << " " << ans_b << endl;

    return 0;
}