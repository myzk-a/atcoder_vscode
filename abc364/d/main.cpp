#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool f(const vector<ll> &A, ll b, ll x, ll k)
{
    auto idx1 = upper_bound(A.begin(), A.end(), b + x) - A.begin() - 1;

    auto idx2 = lower_bound(A.begin(), A.end(), b - x) - A.begin();

    ll cnt = idx1 - idx2 + 1;
    return cnt >= k;
}

int main()
{
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(auto &a : A) cin >> a;
    sort(A.begin(), A.end());

    for(ll i = 0; i < Q; ++i)
    {
        ll b, k;
        cin >> b >> k;

        ll no = -1;
        ll yes = 1000000000;
        while (abs(yes - no) != 1)
        {
            ll mid = (yes + no) / 2;
            if(f(A, b, mid, k))
            {
                yes = mid;
            }
            else
            {
                no = mid;
            }
        }
        cout << yes << endl;
    }
    return 0;
}