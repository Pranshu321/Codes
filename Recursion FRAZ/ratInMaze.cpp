#include <bits/stdc++.h>

using namespace std;

#define int long long

void check(vector<vector<int>> &g, int i, int j, string word)
{
    if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] != 1)
    {
        return;
    }
    if (i == g.size() - 1 and j == g[0].size() - 1)
    {
        cout << word << "\n";
        return;
    }
    int old = g[i][j];
    g[i][j] = 0;

    check(g, i + 1, j, word + 'D');
    check(g, i, j + 1, word + 'R');
    check(g, i - 1, j, word + 'U');
    check(g, i, j - 1, word + 'L');

    g[i][j] = old;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    string word = "";
    check(g, 0, 0, word);
    return 0;
}