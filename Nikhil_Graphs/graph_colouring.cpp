#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, int> mp;
    for (int i =1; i<=n; i++)
    {
        set<int> neighbour;
        for (auto j : adj[i])
        {
            if (mp.find(j) != mp.end())
                neighbour.insert(mp[j]);
        }

        int color = 1;
        while (neighbour.find(color) != neighbour.end())
        {
            color++;
        }
        mp[i] = color;
    }

    for (auto i : mp)
    {
        cout << i.first << "->" << i.second << endl;
    }

    return 0;
}