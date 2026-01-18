#include <bits/stdc++.h>

using namespace std;

#define int long long

int edit_distance(string a, string b, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <=n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <=m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // j-1 addtion , i-1 deletion
            else
            {
                dp[i][j] = min({dp[i - 1][j - 1]+1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            }
        }
    }
    return dp[n][m];
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    cout << edit_distance(a, b, n, m);

    return 0;
}