#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int Min_COin_COunt(int coin[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            if (i == 1)
            {
                if (j % coin[0] == 0)
                    dp[i][j] = j / coin[0];
                else
                    dp[i][j] = INT_MAX - 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = min((1 + dp[i][j - coin[i - 1]]), dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int coin[] = {1, 2, 5};
    int sum = 11, n = 3;
    cout << Min_COin_COunt(coin, n, sum);

    return 0;
}