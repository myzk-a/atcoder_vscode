#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(auto &a : A) cin >> a;

    ll ans = 0;
    for(ll si = 0; si < 2; ++si)
    {
        vector<ll> cnt(N + 1, 0);
        ll right = si;
        for(ll left = si; left < N - 1; left += 2)
        {
            while(right < N - 1)
            {
                if(cnt[A[right]]) break;
                if(A[right] != A[right + 1]) break;
                ++cnt[A[right]];
                right += 2;
            }

            ans = max(ans, right - left);
            if(right == left) right += 2;
            else --cnt[A[left]];
        }
    }

    cout << ans << endl;
    return 0;
}