#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> H(N);
    for(auto &h : H) cin >> h;
    vector<ll> v;
    vector<ll> ans;
    ans.push_back(0);
    for(ll i = N - 2; i >= 0; --i)
    {
        while(true)
        {
            if(v.size() == 0) break;
            if(v.back() < H[i + 1]) v.pop_back();
            else break;
        }
        v.push_back(H[i + 1]);
        ans.push_back(v.size());
    }
    reverse(ans.begin(), ans.end());
    for(auto a : ans) cout << a << " ";
    cout << endl;
    return 0;
}