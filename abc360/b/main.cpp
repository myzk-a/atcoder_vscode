#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S, T;
    cin >> S >> T;

    for(ll w = 1; w < S.size(); ++w)
    {
        for(ll c = 0; c < w; ++c)
        {
            string s = "";
            for(ll i = 0; i < S.size(); i += w)
            {
                if(i + c < S.size())
                {
                    s += S[i + c];
                }
            }
            if(s == T)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}