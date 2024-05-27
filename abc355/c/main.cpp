#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, T;
    cin >> N >> T;
    vector<ll> r(N), c(N), d(2);

    for(ll t = 0; t < T; ++t)
    {
        ll A;
        cin >> A;
        --A;
        ll j = A % N;
        ll i = A / N;
        ++r[i];
        if(r[i] == N)
        {
            cout << t + 1 << endl;
            return 0;
        }

        ++c[j];
        if(c[j] == N)
        {
            cout << t + 1 << endl;
            return 0;
        }

        if(i == j)
        {
            ++d[0];
            if(d[0] == N)
            {
                cout << t + 1 << endl;
                return 0;
            }
        }
        if(i + j == N - 1)
        {
            ++d[1];
            if(d[1] == N)
            {
                cout << t + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}