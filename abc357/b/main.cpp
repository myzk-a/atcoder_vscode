#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;
    int cnt_u = 0, cnt_l = 0;
    for(auto s : S)
    {
        if(isupper(s)) ++cnt_u;
        else ++cnt_l;
    }
    if(cnt_u > cnt_l)
    {
        transform(S.begin(), S.end(),S.begin(), ::toupper);
    }
    else
    {
        transform(S.begin(), S.end(),S.begin(), ::tolower);
    }
    cout << S << endl;
    return 0;
}