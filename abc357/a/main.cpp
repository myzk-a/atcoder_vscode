#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for(auto &h : H) cin >> h;
    for(int i = 0; i < N; ++i)
    {
        if(H[i] <= M) M -= H[i];
        else
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << N << endl;
    return 0;
}