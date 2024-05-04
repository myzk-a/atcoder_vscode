#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N + 1, 0);
    set<ll> S;
    vector<ll> X(Q);
    for(auto &x : X) cin >> x;
    vector<ll> B(N + 1, -1);

    vector<ll> cum_sum(Q + 1, 0);
    for(ll i = 0; i < Q; ++i)
    {
        if(S.count(X[i]))
        {
            S.erase(X[i]);
            A[X[i]] += cum_sum[i] - cum_sum[B[X[i]]];
        }
        else
        {
            S.insert(X[i]);
            B[X[i]] = i;
        }
        cum_sum[i + 1] = cum_sum[i] + S.size();
    }

    for(auto s : S)
    {
        A[s] += cum_sum.back() - cum_sum[B[s]];
    }



    for(ll i = 1; i <= N; ++i) cout << A[i] << " ";
    cout << endl;

    return 0;
}