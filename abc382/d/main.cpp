#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;

    vector<vector<ll>> ans;
    vector<ll> curr;

    auto f = [&](auto f, ll m) -> void
    {
        curr.push_back(m);
        if(curr.size() == N)
        {
            ans.push_back(curr);
            curr.pop_back();
            return;
        }

        if(m + 10 * (N - curr.size()) > M)
        {
            curr.pop_back();
            return;
        }

        ll next = 10 + m;
        for(ll i = next; i <= M; ++i)
        {
            f(f, i);
        }

        curr.pop_back();
        return;
    };

    for(ll i = 1; i <= M; ++i) f(f, i);

    cout << ans.size() << endl;
    for(auto as : ans)
    {
        for(auto a: as) cout << a << " ";
        cout << endl;
    }

    return 0;
}