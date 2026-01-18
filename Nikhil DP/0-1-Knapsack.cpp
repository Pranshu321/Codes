#include <bits/stdc++.h>

using namespace std;

#define int long long

int knapsack(vector<int> &arr, vector<int> &w, int W)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 0;
            }
            else if (w[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + arr[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<int> w = {150, 250, 50, 200, 100};
    vector<int> arr = {300, 400, 100, 350, 200};
    int W = 500;
    cout << knapsack(arr, w, W);

    return 0;
}