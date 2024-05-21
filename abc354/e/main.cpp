#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<vector<pair<ll, ll>>, bool> memo;

bool f(vector<pair<ll, ll>> &p)
{
    if(memo.count(p)) return memo[p];

    vector<pair<ll, ll>> kouho;
    for(ll i = 0; i < p.size(); ++i)
    {
        for(ll j = i + 1; j < p.size();++j)
        {
            if(p[i].first == p[j].first || p[i].second == p[j].second) kouho.emplace_back(i, j);
        }
    }
    if(kouho.empty()) return memo[p] = false;

    for(auto k : kouho)
    {
        vector<pair<ll, ll>> np;
        for(ll i = 0; i < p.size(); ++i)
        {
            if(i == k.first || i == k.second) continue;
            np.push_back(p[i]);
        }
        if(!f(np)) 
        {
            return memo[p] = true;
        }
    }
    return memo[p] = false;
}

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p;
    for(ll i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        p.emplace_back(a, b);
    }
    sort(p.begin(), p.end());
    if(f(p)) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}