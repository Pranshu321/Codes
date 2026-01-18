#include <bits/stdc++.h>

using namespace std;

#define int long long
vector<int> dist(100, INT_MAX);

int dijstra(vector<vector<pair<int, int>>> &adj, int src, int dest)
{
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int w = x.first;
        int node = x.second;
        if (w > dist[node])
            continue;
        for (auto i : adj[node])
        {
            if (dist[i.first] > dist[node] + i.second)
            {
                dist[i.first] = dist[node] + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
    return dist[dest];
}

int32_t
main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src = 0, dest = 4;
    cout << dijstra(adj, src, dest);

    return 0;
}