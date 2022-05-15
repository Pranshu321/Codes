#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

bool visited(int node, int cnt, int n, vector<int> graph[], vector<bool> &vis)
{
    if (cnt == n)
    {
        return true;
    }
    vis[node] = true;

    for (auto i : graph[node])
    {
        if (!vis[i] && visited(i, cnt + 1, n, graph, vis))
        {
            return true;
        }
    }
    vis[node] = false;
    return false;
}

bool Hamiltion_cycle(vector<int> graph[], int n, vector<bool> &vis)
{
    for (int i = 1; i <= n; i++)
    {
        if (visited(i, 1, n, graph, vis))
        {
            return true;
        }
    }
    return false;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<bool> vis(n + 1, false);
    vector<int> graph[n+1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[x].push_back(y);
    }

    if (Hamiltion_cycle(graph, n, vis))
    {
        cout << "Yes, Hamiltion cycle present";
    }
    else
    {
        cout << "No, Hamiltion cycle is not present";
    }

    return 0;
}