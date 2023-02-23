#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int n, m;
const int N = 1e5 + 3;
const int INF = 1e9;
vector<vector<int>> g[N];
vector<int> dist(N), parent(N);
vector<bool> vis(N);
int cost = 0;
void primMST(int source)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }
    set<vector<int>> s;
    dist[source] = 0;
    s.insert({0, source});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << "\n";
        cost += w;
        for (auto it : g[x[1]])
        { // travervelling to other node connected to present node
            if (vis[it[0]])
                continue;
            if (dist[it[0]] > it[1])
            { // If distance in present is greater  than the present weight then we have to swap .
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primMST(0);
    cout << cost << "\n";

    return 0;
}

/* 4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40
output :- 17
*/