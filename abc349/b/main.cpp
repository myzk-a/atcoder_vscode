#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;
    vector<ll> cnt(26, 0);
    for(auto s : S) ++cnt[s - 'a'];
    vector<ll> cnt2(101, 0);
    for(ll i = 0; i < 26; ++i)
    {
        ++cnt2[cnt[i]];
    }
    for(ll i = 1; i <= 100; ++i)
    {
        if(cnt2[i] != 0 && cnt2[i] != 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}