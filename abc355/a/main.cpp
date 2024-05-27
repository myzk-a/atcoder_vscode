#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a == b)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        for(int i = 1; i <= 3; ++i)
        {
            if(i == a || i == b) continue;
            cout << i << endl;
            return 0; 
        }
    }
    return 0;
}