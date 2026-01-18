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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <=n; i++)
    {
        dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + a[i - 2]);
    }

    cout <<dp[n];

    return 0;
}