#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[1001][1001];
bool ispallin(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int pallindrome_partition(string s, int i, int j)
{
    if (i >= j || ispallin(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], pallindrome_partition(s, i, k) + pallindrome_partition(s, k+1 , j) + 1);
    }
    return dp[i][j];
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s;
    int n = s.length();
    cout << pallindrome_partition(s, 0, n - 1);

    return 0;
}