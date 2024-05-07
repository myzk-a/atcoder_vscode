#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<string> A(N), B(N);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    for(ll i = 0; i < N; ++i)
    {
        for(ll j = 0; j < N; ++j)
        {
            if(A[i][j] != B[i][j])
            {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}