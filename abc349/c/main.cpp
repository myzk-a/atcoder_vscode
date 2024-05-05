#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S, T;
    cin >> S >> T;

    std::transform(S.begin(), S.end(), S.begin(), ::toupper);

    bool f = false;
    ll i, j, k;
    for(i = 0; i < S.size(); ++i)
    {
        if(S[i] == T[0])
        {
            f = true;
            break;
        }
    }

    if(f)
    {
        f = false;
        for(j = i + 1; j < S.size(); ++j)
        {
            if(S[j] == T[1])
            {
                f = true;
                break;
            }
        }
    }

    if(f)
    {
        for(k = j + 1; k < S.size();++k)
        {
            if(S[k] == T[2])
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
        if(T[2] == 'X')
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}