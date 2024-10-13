#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(vector<vector<char>> &g, int i, int j, string word, int k)
{
    if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || word[k] != g[i][j])
    {
        return false;
    }
    if (k == word.size() - 1)
    {
        return true;
    }
    g[i][j] = '#';
    if (check(g, i + 1, j, word, k + 1) || check(g, i - 1, j, word, k + 1) || check(g, i, j + 1, word, k + 1) || check(g, i, j - 1, word, k + 1))
    {
        return true;
    }
    g[i][j] = word[k];
    return false;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    string word;
    cin >> word;

    auto ans = check(g, 0, 0, word, 0);
    if (ans)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}