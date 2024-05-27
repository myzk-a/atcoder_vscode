#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> comp( const vector<ll> &v)
{
    vector<ll> _v = v;
    // sort(_v.begin(), _v.end());
    // _v.erase(unique(_v.begin(), _v.end()), _v.end());
    vector<ll> res(v.size());
    for (ll i = 0; i < v.size(); ++i) res[i] = lower_bound(_v.begin(), _v.end(), v[i]) - _v.begin();
    return res;
};


int main()
{
    ll N;
    cin >> N;
    vector<ll> L(N), R(N);
    for(ll i = 0; i < N; ++i) cin >> L[i] >> R[i];

    auto s = set<ll>();
    for(auto l : L) s.insert(l);
    for(auto r : R) s.insert(r);
    vector<ll> v;
    for(auto x : s) v.push_back(x);
    auto c = comp(v);
    unordered_map<ll, ll> conv;
    for(ll i = 0; i < c.size(); ++i) conv[v[i]] = c[i];

    vector<ll> sum_r(c.size() + 1, 0), sum_l(c.size() + 1, 0);
    for(auto l : L) ++sum_l[conv[l]];
    for(auto r : R) ++sum_r[conv[r]];
    for(ll i = 1; i < sum_l.size(); ++i) sum_l[i] += sum_l[i-1];
    for(ll i = 1; i < sum_r.size(); ++i) sum_r[i] += sum_r[i-1];

    ll ans =  N * (N - 1);
    for(ll i = 0; i < N; ++i)
    {
        ans -= sum_l.back() - sum_l[conv[R[i]]];
        if(conv[L[i]] > 0) ans -= sum_r[conv[L[i]] - 1];
    }

    cout << ans / 2 << endl;

    return 0;

}