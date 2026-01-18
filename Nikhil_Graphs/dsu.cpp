#include <bits/stdc++.h>

using namespace std;

int findparent(int u, vector<int> &parent)
{
    if (parent[u] == u)
    {
        return parent[u];
    }
    return parent[u] = findparent(parent[u], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = findparent(u, parent);
    int pv = findparent(v, parent);

    if (rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    }
    else if (rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }
    else
    {
        parent[pu] = pv;
        rank[pv]++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n), rank(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v, parent, rank);
    }

    unordered_map<int, vector<int>> sets;
    for (int i = 0; i < n; i++)
    {
        int root = findparent(i, parent);
        sets[root].push_back(i);
    }

    cout << "Components\n";
    for (auto i : sets)
    {
        cout << i.first << "->";
        for (int node : i.second)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}