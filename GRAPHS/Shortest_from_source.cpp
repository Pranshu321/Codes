#include <bits/stdc++.h>

using namespace std;
const int INF = 1e5 + 10;
#define ll long long int

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    vector<int> dist(n, INF);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    for (int i = 0; i < n; i++)
    {
        auto x = q.front();
        q.pop();
        for (auto j : g[x])
        {
            if (dist[x] + 1 < dist[j])
            {
                dist[j] = dist[x] + 1;
                q.push(j);
            }
        }
    }
    for (auto i : dist)
    {
        cout << i << " ";
    }

    return 0;
}