#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<string> s(N);
    ll sum = 0;
    for(ll i = 0; i < N; ++i)
    {
        ll c;
        cin >> s[i] >> c;
        sum += c;
    }

    sort(s.begin(), s.end());
    ll index = sum % N;
    cout << s[index] << endl;
    return 0;
}