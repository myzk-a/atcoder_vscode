#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N + 1);
    for(ll i = 1; i <= N; ++i) cin >> A[i];

    auto _A = A;
    for(ll i = 1; i <= N; ++i) A.push_back(_A[i]);

    vector<ll> cum_sum(2 * N + 1, 0);
    for(ll i = 1; i <= 2 * N; ++i) cum_sum[i] = cum_sum[i - 1] + A[i];

    ll target = S % cum_sum[N];

    ll right = 0;
    for(ll left = 0; left < 2 * N; ++left)
    {
        while(right <= 2 * N)
        {
            if(cum_sum[right] - cum_sum[left] > target) break;
            if(cum_sum[right] - cum_sum[left] == target)
            {
                cout << "Yes" << endl;
                return 0;
            }
            ++right;
        }
    }

    cout << "No" << endl;
    return 0;
}