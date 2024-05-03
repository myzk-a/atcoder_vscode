#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> D(N);
    for(auto &d : D) cin >> d;
    for(auto &d : D) d %= (A + B);

    set<ll> E;
    for(auto d : D) E.insert(d);

    vector<ll> F;
    for(auto e : E) F.push_back(e);

    for(ll i = 0; i < F.size(); ++i)
    {
        ll tmp = F[(i + 1) % F.size()] - F[i] - 1;
        if(tmp < 0) tmp += A + B;
        if(tmp >= B)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}