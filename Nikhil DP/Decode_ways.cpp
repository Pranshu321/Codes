#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i < n; i++)
    {
        auto onedigit = s.substr(i - 1, i);
        auto twodigit = s.substr(i - 2, i);

        if (stoi(onedigit) >= 1) // for the zero it should be not valid case
        {
            dp[i] += dp[i - 1];
        }
        if (stoi(twodigit) >= 10 and stoi(twodigit) <= 26) // also for the cases like 06 it is invalid
        {
            dp[i] += dp[i - 2];
        }
    }
    cout << dp[n-1];
    return 0;
}