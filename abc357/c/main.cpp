#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> f(int n)
{
    if(n == 0)
    {
        vector<vector<ll>> ans(1, vector<ll>(1, 1));
        return ans;
    }
    int m = 1;
    for(int i = 1; i <= n; ++i) m *= 3;
    vector<vector<ll>> ans(m, vector<ll>(m, 0));
    for(ll i = 0; i < 3; ++i)
    {
        for(ll j = 0; j < 3; ++j)
        {
            if(i == 1 && j == 1) continue;
            else
            {
                auto x = f(n - 1);
                for(ll k = 0; k < x.size(); ++k)
                {
                    for(ll l = 0; l < x.size(); ++l)
                    {
                        ans[i * m / 3 + k][j * m / 3 + l] = x[k][l];
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    auto ans = f(n);
    for(ll i = 0; i < ans.size(); ++i)
    {
        for(ll j = 0; j < ans.size(); ++j)
        {
            if(ans[i][j] == 1) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}