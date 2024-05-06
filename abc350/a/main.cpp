#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;
    auto sub = S.substr(3, 3);
    auto num = stoi(sub);
    if(num != 316 && num <= 349 && 1 <= num)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}