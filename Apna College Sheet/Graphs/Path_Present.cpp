#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(vector<pair<int, int>> g[], vector<int> &path, int src, int k)
{
    if (k <= 0)
    {
        return true;
    }

    for (auto i : g[src])
    {
        if (path[i.first])
        {
            continue;
        }
        if (i.second >= k)
        {
            return true;
        }
        path[i.first] = true;
        if (check(g, path, i.first, k - i.second))
        {
            return true;
        }
        path[i.first] = false;
    }
    return false;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n];
    vector<int> path(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int src = 0;
    path[src] = true;
    int k = 65;
    if (check(g, path, src, k))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}