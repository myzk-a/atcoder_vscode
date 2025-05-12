#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool f(ll l, ll r, ll k, const vector<ll> &v1, const vector<ll> &v2, const vector<ll> &vs)
{
    auto idx = l - 1;
    if(k > 0)
    {
        if(v1.size() == 0) return false;
        idx = lower_bound(v1.begin(), v1.end(), l) - v1.begin();
        idx += k - 1;
        if(idx > v1.size() - 1) return false;
        idx = v1[idx];
    }

    if(vs.size() == 0) return false;
    auto idx2 = lower_bound(vs.begin(), vs.end(), idx + 1) - vs.begin();
    if(idx2 > vs.size() - 1) return false;
    idx2 = vs[idx2];
    if(idx2 > r) return false;

    if(k <= 0) return true;

    if(v2.size() == 0) return false;
    auto idx3 = lower_bound(v2.begin(), v2.end(), idx2 + 1) - v2.begin();
    idx3 += k - 1;
    if(idx3 > v2.size() - 1) return false;
    idx3 = v2[idx3];

    return idx3 <= r;
}

int main()
{
    ll N, Q;
    string S;
    cin >> N >> Q >> S;

    vector<ll> l1, l2, ls;
    for(ll i = 0; i < N; ++i)
    {
        if(S[i] == '1') l1.push_back(i);
        else if(S[i] =='2') l2.push_back(i);
        else ls.push_back(i);
    }

    for(ll q = 0; q < Q; ++q)
    {
        ll l, r;
        cin >> l >> r;
        --l;
        --r;
        ll ok = -1;
        ll ng = N;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if(f(l, r, mid, l1, l2, ls)) ok = mid;
            else ng = mid;
        }
        ll ans = 0;
        if(ok >= 0) ans = ok * 2 + 1;
        cout << ans << endl;
    }
    return 0;
}