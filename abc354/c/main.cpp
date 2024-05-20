#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<pair<pair<ll, ll>, ll>> p;
    for(ll i = 0; i < N; ++i)
    {
        ll a, c;
        cin >> a >> c;
        p.push_back({{a, c}, i + 1});
    }
    sort(p.begin(), p.end());
    vector<pair<pair<ll,ll>, ll>> v;
    v.push_back(p[0]);

    for(ll i = 1; i < N; ++i)
    {
        while(true)
        {
            if(v.empty())
            {
                v.push_back(p[i]);
                break;
            }
            if(p[i].first.first > v.back().first.first && p[i].first.second < v.back().first.second)
            {
                v.pop_back();
            }
            else
            {
                v.push_back(p[i]);
                break;
            }
        }
    }

    set<ll> ans;
    for(auto x : v)
    {
        ans.insert(x.second);
    }
    cout << ans.size() << endl;
    for(auto a : ans) cout << a << " ";
    cout << endl;

    return 0;
}