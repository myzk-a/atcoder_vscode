#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;
    for(const auto &s : S)
    {
        if(s == 'R')
        {
            cout << "Yes" << endl;
            return 0;
        }
        if(s == 'M')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    return 0;
}