#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> A(2 * n);
    for(auto &a : A) cin >> a;

    int ans = 0;
    for(int i = 0; i + 2 < 2 * n; ++i)
    {
        if(A[i] == A[i + 2]) ++ans;
    }
    cout << ans << endl;
    return 0;
}