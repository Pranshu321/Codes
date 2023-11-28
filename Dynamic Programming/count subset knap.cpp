#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int count_subset(int a[], int n, int sum)
{
    int dp[n + 1][(sum + 1)];
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
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
    int a[] = {2, 3, 5, 6, 8, 10};
    int n = 6;
    int sum = 11;
    cout << count_subset(a, n, sum);

    return 0;
}