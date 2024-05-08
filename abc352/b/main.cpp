#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S, T;
    cin >> S >> T;

    ll si = 0;

    for(ll i = 0; i < T.size(); ++i)
    {
        if(si < S.size())
        {
            if(S[si] == T[i])
            {
                ++si;
                cout << i + 1 << " ";
            }
        }
    }
    cout << endl;
    return 0;
}