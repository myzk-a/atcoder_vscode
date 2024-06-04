#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> x(5 * n);
    for(auto &v : x) cin >> v;

    sort(x.begin(), x.end());

    int sum = 0;
    for(int i = n; i < 4 * n; ++i) sum += x[i];

    double ans = static_cast<double>(sum) / static_cast<double>(3 * n);

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}