#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    int m;
    cin >> m;
    vector<int> vis(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ans = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int node = x.second;
        int w = x.first;
        if (vis[node])
            continue;
        vis[node] = 1;
        ans += w;
        for (auto i : adj[node])
        {
            int adjnode = i.first;
            int adjw = i.second;
            if (!vis[adjnode])
            {
                pq.push({adjw, adjnode});
            }
        }
    }
    cout << ans;

    return 0;
}