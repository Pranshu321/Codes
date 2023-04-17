#include <bits/stdc++.h>

using namespace std;

#define int long long

void vertexCover(int n, int m, vector<int> g[], vector<bool> &vis)
{
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            for (auto j : g[i])
            {
                if (!vis[j])
                {
                    vis[i] = true;
                    vis[j] = true;
                    break;
                }
            }
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            cout << i << " ";
        }
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    vector<bool> vis(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vertexCover(n, m, g, vis);

    return 0;
}