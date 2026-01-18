#include <bits/stdc++.h>

using namespace std;

#define int long long

int findparent(int u, vector<int> &parent)
{
    if (parent[u] == u)
    {
        return parent[u];
    }
    return parent[u] = findparent(parent[u], parent);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({w, u, v});
    }

    sort(adj.begin(), adj.end());
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int mst_weight = 0;
    for (auto i : adj)
    {
        int x, y, z;
        tie(x, y, z) = i;
        int pu = findparent(y, parent);
        int pv = findparent(z, parent);
        if (pu != pv)
        {
            parent[pu] = pv;
            mst_weight += x;
        }
    }

    cout << mst_weight;

    return 0;
}