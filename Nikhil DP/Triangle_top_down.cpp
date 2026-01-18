#include <bits/stdc++.h>

using namespace std;

#define int long long

int recur(vector<vector<int>> &a, vector<vector<int>> &dp, int i, int j, int n)
{
    if (i >= n || j >= n)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = a[i][j] + min(recur(a, dp, i + 1, j + 1, n), recur(a, dp, i + 1, j, n));
    return dp[i][j];
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<vector<int>> a = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << recur(a, dp, 0, 0, n);

    return 0;
}