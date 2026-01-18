#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int max_side = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                dp[i][j] == 0;
            }
            else if (i == 0)
            {
                if (a[i][j] == 1)
                    dp[i][j] = 1;
            }
            else if (j == 0)
            {
                if (a[i][j] == 1)
                    dp[i][j] = 1;
            }
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});

            max_side = max(max_side, dp[i][j]);
        }
    }
    cout << max_side;

    return 0;
}