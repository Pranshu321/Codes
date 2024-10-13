#include <bits/stdc++.h>

using namespace std;

#define int long long
// N queen Problem
vector<vector<int>> ans;
bool isValid(int i, int j, vector<vector<int>> &g, int n)
{
    int row = i;
    int col = j;
    // UP
    while (row >= 0)
    {
        if (g[row][col] == 1)
        {
            return false;
        }
        row--;
    }
    row = i;
    col = j;
    // Top Right
    while (row >= 0 && col < n)
    {
        if (g[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    // Top left
    row = i;
    col = j;
    while (row >= 0 and col >= 0)
    {
        if (g[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    // down
    row = i;
    col = j;
    while (row < n)
    {
        if (g[row][col] == 1)
        {
            return false;
        }
        row++;
    }

    // down left
    row = i;
    col = j;
    while (row < n and col >= 0)
    {
        if (g[row][col] == 1)
        {
            return false;
        }
        row++;
        col--;
    }

    // down right
    row = i;
    col = j;
    while (row < n and col < n)
    {
        if (g[row][col] == 1)
        {
            return false;
        }
        row++;
        col++;
    }

    return true;
}

void solve(int i, vector<vector<int>> &g)
{
    if (i == g.size())
    {
        for (int r = 0; r < g.size(); r++)
        {
            for (int c = 0; c < g.size(); c++)
            {
                if (g[r][c] == 1)
                    cout << "Q"
                         << " ";
                else
                    cout << "X"
                         << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    for (int j = 0; j < g.size(); j++)
    {
        if (isValid(i, j, g, g.size()))
        {
            g[i][j] = 1;
            solve(i + 1, g);
            g[i][j] = 0;
        }
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // N queen Problem
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    solve(0, g);
    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}