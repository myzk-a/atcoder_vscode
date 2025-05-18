#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll divisor(long long n)
{
    vector<long long> res;
    for (long long i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    // sort(res.begin(), res.end());
    return res.size();
}

int main()
{
    ll N;
    cin >> N;

    vector<ll> is_prime(10000000LL, true);
    vector<ll> prime;

    for(ll i = 2; i * i <= N; ++i)
    {
        if(!is_prime[i]) continue;
        prime.push_back(i);
        for(ll j = i + i; j * j <= N; j += i)
        {
            is_prime[j] = false;
        }
    }

    ll ans = 0;
    cerr << "prime size : " << prime.size() << endl; 
    for(ll i = 0; i < prime.size(); ++i)
    {
        for(ll j = i + 1; j < prime.size(); ++j)
        {
            ll tmp1 = prime[i] * prime[i];
            ll tmp2 = prime[j] * prime[j];
            if( tmp2 >  N / tmp1) break;
            ++ans;
            // cerr << tmp << " " << divisor(tmp) << endl;
            // if(divisor(tmp) != 9)
            // {
            //     cerr << "error" << tmp << " " << divisor(tmp) << endl;
            // }
        }
    }

    for(ll i = 0; i < prime.size(); ++i)
    {
        ll tmp = prime[i] * prime[i];
        tmp *= tmp;
        tmp *= tmp;
        if(tmp > N) break;
        ++ans;
    }

    cout << ans << endl;
    return 0;
}