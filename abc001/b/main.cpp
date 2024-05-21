#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int m;
    cin >> m;
    string vv;
    if(m < 100) vv = "00";
    else if(100 <= m && m <= 5000)
    {
        ll tmp = m / 100;
        if(tmp < 10) vv = "0" + to_string(tmp);
        else vv = to_string(tmp);
    }
    else if(6000 <= m && m <= 30000)
    {
        ll tmp = m / 1000 + 50;
        vv = to_string(tmp);
    }
    else if(35000 <= m && m <= 70000)
    {
        ll tmp = (m / 1000 - 30) / 5 + 80;
        vv = to_string(tmp);
    }
    else vv = "89";

    cout << vv << endl;
    return 0;
}