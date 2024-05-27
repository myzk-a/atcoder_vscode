#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    vector<pair<int, int>> p;
    for(auto &x : a) p.emplace_back(x, 1);
    for(auto &x : b) p.emplace_back(x, 2);
    sort(p.begin(), p.end());

    for(int i = 0; i < p.size() - 1; ++i)
    {
        if(p[i].second == p[i+1].second && p[i].second == 1)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}