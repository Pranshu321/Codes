#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int Target_sum(int a[], int sum, int n)
{
    int dp[n + 1][(sum + 1)];
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= sum; i++)
    {
        dp[i][0] = 1;
    }
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
    int a[] = {1, 1, 2, 3};
    int sum = 1, arr_sum = 0, n = 4; // in this we take altwer nate signs and find subset having sum equal to given sum
    for (int i = 0; i < n; i++)
    {
        arr_sum += a[i];
    }
    int val = (arr_sum + sum) / 2; // same as previous
    cout << Target_sum(a, val, 4);

    return 0;
}