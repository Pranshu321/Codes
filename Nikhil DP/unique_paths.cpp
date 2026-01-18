#include <bits/stdc++.h>

using namespace std;

#define int long long

int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
    {
        return 0;
    }
    if (i == m - 1 and j == n - 1)
    {
        return 1;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = solve(i + 1, j, m, n, dp) + solve(i, j + 1, m, n, dp);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int m;
    int n;
    cin >> m >> n;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << solve(0, 0, m, n, dp);

    return 0;
}