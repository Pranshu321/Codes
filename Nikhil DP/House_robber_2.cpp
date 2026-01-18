#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<int> a = {2, 7, 3, 1, 4, 2, 1, 8};
    int n = a.size();
    vector<int> dp(n + 1, 0);
    dp[0] = a[0];
    dp[1] = a[1];
    // skip last element
    for (int i = 2; i < n - 1; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }

    int max1 = dp[n - 2];
    vector<int> dp2(n + 2, 0);
    // skip first element
    for (int i = n - 1; i >= 1; i--)
    {
        dp2[i] = max(dp2[i + 1], dp2[i + 2] + a[i]);
    }
    cout << max(max1, dp2[1]);

    return 0;
}