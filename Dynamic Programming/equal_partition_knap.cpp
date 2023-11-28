#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool equal_partition(int a[], int n, int sum)
{
    if (sum % 2 != 0)
        return false;
    int dp[n + 1][(sum / 2) + 1];
    for (int i = 0; i <= sum / 2; i++)
        dp[0][i] = false;
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum / 2; j++)
        {
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum / 2];
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int a[] = {1, 5, 11, 5};
    int n = 4;
    int sum = 0; // This sum is to calculate the sum of whole array.
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (equal_partition(a, n, sum))
        cout << "lets go";
    else
    {
        cout << "chala ja bsdk";
    }

    return 0;
}