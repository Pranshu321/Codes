#include <bits/stdc++.h>

using namespace std;

#define int long long

int solve(string a, string b, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
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

    cout << solve(a, b, n, m);

    return 0;
}