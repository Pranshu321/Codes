#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> bellman(vector<vector<int>> &adj, int src, int n)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int j = 0; j < n; j++)
    {
        for (auto i : adj)
        {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            if (dist[u] != INT_MAX and dist[v] > dist[u] + w)
            {
                if (j == n - 1)
                    return {-1};
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<vector<int>> adj;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
    int src = 0;
    auto ans = bellman(adj, src, n);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}