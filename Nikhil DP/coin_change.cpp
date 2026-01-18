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
    int amount;
    cin >> amount;
    vector<int> dp(amount + 1, INT_MAX);
    dp[0]=0;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : a)
        {
            if (i >= coin and dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    if(dp[amount]==INT_MAX) cout<<-1;
    else cout<<dp[amount];

    return 0;
}