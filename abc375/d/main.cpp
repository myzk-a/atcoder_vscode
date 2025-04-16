#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;

    vector<vector<ll>> cnt(26);
    for(ll i = 0; i < S.size(); ++i)
    {
        cnt[S[i] - 'A'].push_back(i);
    }

    ll ans = 0;
    for(ll i = 0; i < cnt.size(); ++i)
    {
        if(cnt[i].size() <= 1) continue;
        for(ll j = 1; j < cnt[i].size(); ++j)
        {
            ans += j * (cnt[i].size() - j) * (cnt[i][j] - cnt[i][j - 1] - 1);
            ans += j * (cnt[i].size() - j - 1);
        }
    }

    cout << ans << endl;

    return 0;
}