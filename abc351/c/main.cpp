#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(auto &a : A) cin >> a;

    vector<ll> b;
    for(auto a : A)
    {
        ll next = a;
        while(b.size() > 0 && b.back() == next)
        {
            ++next;
            b.pop_back();
        }
        b.push_back(next);
    }

    cout << b.size() << endl;

    return 0;
}