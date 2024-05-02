#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &a : A) cin >> a;

    for(auto a: A)
    {
        if(a % K == 0) cout << a / K << " ";
    }
    cout << endl;
    return 0;
}