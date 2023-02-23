#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, vis, adj);
        }
    }
    st.push(node);
}

void revdfs(int node, vector<int> &vis, vector<int> adj[])
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            revdfs(it, vis, adj);
        }
    }
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }

    vector<int> transpose[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            revdfs(node, vis, transpose);
            cout << "\n";
        }
    }

    return 0;
}