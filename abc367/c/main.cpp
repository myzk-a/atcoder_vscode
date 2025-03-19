#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;
vector<string> ans;

void f(string &s, ll n, const vector<ll>& r)
{
    if(s.size() == N)
    {
        ll sum = 0;
        for(auto ch : s) sum += ch - '0';
        if(sum % K == 0) ans.push_back(s);
        return;
    }

    for(ll i = 1; i<= r[n]; ++i)
    {
        string _s = s;
        _s += to_string(i);
        f(_s, n + 1, r);
    }
}

int main()
{
    cin >> N >> K;
    vector<ll> R(N);
    for(auto &r : R) cin >> r;

    string s = "";
    f(s, 0, R);

    sort(ans.begin(), ans.end());
    for(auto a : ans)
    {
        for(auto x : a) cout << x << " ";
        cout << endl;
    }

    return 0;
}