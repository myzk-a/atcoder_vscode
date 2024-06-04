#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    string S;
    cin >> N >> S;

    ll x = 0;
    ll y = 0;

    set<pair<ll, ll>> s;
    s.insert({x, y});

    for(ll i = 0; i < N; ++i)
    {
        if(S[i] == 'R') ++x;
        if(S[i] == 'L') --x;
        if(S[i] == 'U') ++y;
        if(S[i] == 'D') --y;

        if(s.count({x, y}))
        {
            cout << "Yes" << endl;
            return 0;
        }
        s.insert({x, y});
    }

    cout << "No" << endl;

    return 0;
}