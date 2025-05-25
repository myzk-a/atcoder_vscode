#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, M, SX, SY;
    cin >> N >> M >> SX >> SY;

    using D = map<ll, set<ll>>;
    D xs, ys;
    for(ll i = 0; i < N; ++i)
    {
        ll x, y;
        cin >> x >> y;
        xs[y].insert(x);
        ys[x].insert(y);
    }

    ll ans = 0;

    auto f = [&](D& xs, D& ys, ll l, ll r, ll y) -> void
    {
        if(l > r) swap(l, r);
        while (1)
        {
            auto iter = xs[y].lower_bound(l);
            if(iter == xs[y].end()) break;
            if(*iter > r) break;

            ++ans;
            ys[*iter].erase(y);
            xs[y].erase(iter);
        }
        return;
    };

    for(ll i = 0; i < M; ++i)
    {
        char d;
        ll c;
        cin >> d >> c;
        ll nx = SX;
        ll ny = SY;
        if(d == 'U') ny += c;
        if(d == 'D') ny -= c;
        if(d == 'L') nx -= c;
        if(d == 'R') nx += c;
        if(SY == ny) f(xs, ys, SX, nx, SY);
        else f(ys, xs, SY, ny, SX);

        SX = nx;
        SY = ny;
    }
    cout << SX << " " << SY << " " << ans << endl;
    return 0;
}