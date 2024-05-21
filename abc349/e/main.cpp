#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool win(vector<vector<ll>>&b)
{
    for(ll i = 0; i < 3; ++i)
    {
        if(b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] == 1) return true;
        if(b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] == 1) return true;
    }
    if(b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] == 1) return true;
    if(b[2][0] == b[1][1] && b[1][1] == b[0][2] && b[0][2] == 1) return true;
    return false;
}

bool f(vector<vector<ll>> &a, vector<vector<ll>>& b)
{
    bool end = true;
    for(ll i = 0; i < 3; ++i)
    {
        for(ll j = 0; j < 3; ++j)
        {
            if(b[i][j] == 0) end = false;
        }
    }
    if(end)
    {
        ll s = 0;
        for(ll i = 0; i < 3; ++i)
        {
            for(ll j = 0; j < 3; ++j) s += a[i][j] * b[i][j];
        }
        return s > 0;
    }
    for(ll i = 0; i < 3; ++i)
    {
        for(ll j = 0; j < 3; ++j)
        {
            if(b[i][j] == 0)
            {
                auto n_b = b;
                n_b[i][j] = 1;
                if(win(n_b)) return true;
                for(ll k = 0; k < 3; ++k)
                {
                    for(ll l = 0; l < 3; ++l)
                    {
                        n_b[k][l] *= -1;
                    }
                }
                if(!f(a, n_b)) return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<ll>> a(3, vector<ll>(3));
    for(ll i = 0; i < 3; ++i)
    {
        for(ll j = 0; j < 3; ++j) cin >> a[i][j];
    }

    vector<vector<ll>> b(3, vector<ll>(3, 0));
    if(f(a, b)) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}