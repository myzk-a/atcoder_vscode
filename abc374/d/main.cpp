#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

double dist(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

}

int main()
{
    ll N;
    double S, T;
    cin >> N >> S >> T;
    vector<ll> A(N), B(N), C(N), D(N);
    for(ll i = 0; i < N; ++i) cin >> A[i] >> B[i] >> C[i] >> D[i];

    double ans = INF;

    vector<ll> v;
    for(ll i = 0; i < N; ++i) v.push_back(i);

    do
    {
        for(ll mask = 0; mask < (1LL << N); ++mask)
        {
            ll cx = 0;
            ll cy = 0;
            double tmp = 0;
            for(auto i : v)
            {
                if((mask & (1LL << i)) != 0)
                {
                    tmp += dist(cx, cy, A[i], B[i]) * T;
                    tmp += dist(A[i], B[i], C[i], D[i]) * S;
                    cx = C[i];
                    cy = D[i];
                }
                else
                {
                    tmp += dist(cx, cy, C[i], D[i]) * T;
                    tmp += dist(A[i], B[i], C[i], D[i]) * S;
                    cx = A[i];
                    cy = B[i];
                }
            }
            ans = min(ans, tmp);
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << fixed << setprecision(10);
    cout << (ans / (double)(S * T)) << endl;

    return 0;
}