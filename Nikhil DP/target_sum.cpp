#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    unordered_map<int, int> dp;
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int num : a)
    {
        unordered_map<int, int> newdp;
        for (auto i : dp)
        {
            int ways = i.second;
            if (newdp.find(i.first + num) != newdp.end())
            {
                int x = newdp[i.first + num];
                newdp[i.first + num] = x + ways;
            }
            else
            {
                newdp[i.first + num] = ways;
            }

            if (newdp.find(i.first - num) != newdp.end())
            {
                int x = newdp[i.first - num];
                newdp[i.first - num] = x + ways;
            }
            else
            {
                newdp[i.first - num] = ways;
            }
        }
        dp = newdp;
    }
    cout << dp[k];

    return 0;
}

/*
[1,1,1,1,1]
So, here we are trying use dp , for the +/- operations
lets say we know for the dp[0] --> 1 ways

newdp for this as we are adding 1
dp[-1] --> 1 ways
dp[1] --> 1 ways

if we add new index 1 , 1
again newdp with prev step dp copied
dp[-1] ---> add 1 (0)
    |-----> sub 1 (-2)
                            [Here we can see, we get zero two times] our new dp be like
                                0 -> 2
                                2 -> 1
                                -2 -> 1
dp[1]----> add 1 (2)
    |----> sub 1 (0)     

*/