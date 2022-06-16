#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
           vector<vector<int>> &vis)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // downwards
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i + 1, j, a, n, ans, move + 'D', vis);
        vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j - 1, a, n, ans, move + 'L', vis);
        vis[i][j] = 0;
    }

    // right
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j + 1, a, n, ans, move + 'R', vis);
        vis[i][j] = 0;
    }

    // Upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i - 1, j, a, n, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}

vector<string> findpath(vector<vector<int>> &m, int row)
{
    vector<string> ans;
    vector<vector<int>> vis(row, vector<int>(row, 0));

    if (m[0][0] == 1)
        solve(0, 0, m, row, ans, "", vis);
    return ans;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<vector<int>> maze;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        maze.push_back(temp);
    }

    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
        

    vector<string> result = findpath(maze, n);
    if (result.size() == 0)
    {
        cout << "-1";
    }
    else
    {
        for (auto i : result)
        {
            cout << i << " ";
        }
    }

    return 0;
}