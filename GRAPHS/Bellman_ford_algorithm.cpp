#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int INF = 1e7 + 10;
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int src;
    cin >> src;
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v], w + dist[u]); // relaxing the or updating the dist of each node
        }
    }
    for (auto i : dist)
        cout << i << " ";

    return 0;
}