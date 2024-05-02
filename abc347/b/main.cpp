#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;
    set<string> SS;

    for(ll i = 0; i < S.size(); ++i)
    {
        for(ll j = 1; j <= S.size() - i; ++j)
        {
            auto sub = S.substr(i, j);
            SS.insert(sub);
        }
    }

    cout << SS.size() << endl;
    return 0;
}