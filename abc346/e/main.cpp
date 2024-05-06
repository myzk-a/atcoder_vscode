#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll H, W, M;
    cin >> H >> W >> M;
    set<ll> C;
    set<ll> R;
    vector<ll> cnt(200001, 0);
    cnt[0] = H * W;

    vector<ll> T(M), A(M), X(M);
    for(ll i = 0; i < M; ++i) 
    {
        cin >> T[i] >> A[i] >> X[i];
        --A[i];
    }
    for(ll i = M - 1; i >= 0; --i)
    {
        if(T[i] == 1)
        {
            if(R.count(A[i])) continue;
            R.insert(A[i]);
            cnt[X[i]] += W - C.size();
            cnt[0] -= W - C.size();
        }
        else
        {
            if(C.count(A[i])) continue;
            C.insert(A[i]);
            cnt[X[i]] += H - R.size();
            cnt[0] -= H - R.size();
        }
    }

    ll k = 0;
    for(ll i = 0; i < cnt.size(); ++i)
    {
        if(cnt[i] > 0) ++k;
    }

    cout << k << endl;
    for(ll i = 0; i < cnt.size(); ++i)
    {
        if(cnt[i] > 0)
        {
            cout << i << " " << cnt[i] << endl;
        }
    }

    return 0;
}