#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    reverse(S.begin(), S.end());

    vector<ll> d(N + 1);
    for(ll i = N - 1; i >= 0; --i)
    {
        d[i] = d[i + 1] + (S[i] - '0') * (N - i);
    }

    string ans = "";
    for(ll i = 0; i < N; ++i)
    {
        ll tmp = d[i] % 10;
        ans += to_string(tmp);
        d[i + 1] += d[i] / 10;
    }
    while(d[N] != 0)
    {
        ans += to_string(d[N] % 10);
        d[N] /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}