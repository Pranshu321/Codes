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
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src = 0, dest = 4;
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        for (auto i : adj[x])
        {
            if (dist[i] > dist[x] + 1)
            {
                dist[i] = dist[x] + 1;
                q.push(i);
            }
        }
    }
    cout << dist[dest];
    return 0;
}