#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<vector<int>> a = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        auto temp = a[i];
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = temp[j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    cout<<dp[0][0];

    return 0;
}