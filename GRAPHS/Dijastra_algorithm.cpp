#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int inf = 1e5;
// Dijastra Algo
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> dist(n + 1, inf);
    vector<vector<pair<int, int>>> graph(n + 1); // we have to add  u,v vertex and
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int source;
    cin >> source;    // entering staring node where from we have to start
    dist[source] = 0; // initialising dist with 0
    set<pair<int, int>> s;
    s.insert({0, source});

    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto it : graph[x.second])
        {
            if (dist[it.first] > dist[x.second] + it.second)
            {                                                // if dist of node u is greater than adding the dist of saved node and sum of the weight to other niode.
                s.erase({dist[it.first], it.first});         // then erase it and update
                dist[it.first] = dist[x.second] + it.second; // update dist
                s.insert({dist[it.first], it.first});        // reenter the dist
            }
        }
    }
    for (int i = 1; i <= n; i++)
    { // printing of the dist;
        if (dist[i] < inf)
            cout << dist[i] << " ";
        else
            cout << -1 << " ";
    }

    return 0;
}