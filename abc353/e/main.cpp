#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Trie
{
    struct Node
    {
        ll cnt;
        map<char, ll> to;
        Node() : cnt(0) {}
    };

    vector<Node> d;
    Trie() : d(1) {}

    ll ans;

    void add(const string& s)
    {
        ll v = 0;
        for(auto c : s)
        {
            if(!d[v].to.count(c))
            {
                d[v].to[c] = d.size();
                d.push_back(Node());
            }
            v = d[v].to[c];
        }
        ++d[v].cnt;
    }

    ll dfs(ll v)
    {
        ll res = d[v].cnt;
        for(auto nv : d[v].to)
        {
            res += dfs(nv.second);
        }
        if(v) ans += (res * (res - 1)) / 2;
        return res;
    }

    ll solve()
    {
        ans = 0;
        dfs(0);
        return ans;
    }
};

int main()
{
    ll N;
    cin >> N;
    Trie t = Trie();
    for(ll i = 0; i < N; ++i)
    {
        string S;
        cin >> S;
        t.add(S);
    }

    ll ans = t.solve();
    cout << ans << endl;

    return 0;
}