#include <bits/stdc++.h>

using namespace std;

#define int long long
vector<int> dp(100, -1);
int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n-1)+fibo(n-2);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // dp[0] = 0;
    // dp[1] = 1;
    int n; cin>>n;
    cout<<fibo(n);

    return 0;
}