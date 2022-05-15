#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
int dp[21][(1 << 21)];
int cost[1001][1001];
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int solve(int i, int mask, int n)
{
    if (mask == 0)
    {
        return cost[i][0];
    }
    if (dp[i][mask] != -1)
    {
        return dp[i][mask];
    }
    int ans = INT16_MAX;
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))
            ans = min(ans, cost[i][j] + solve(i + 1, (mask ^ (1 << j)), n));
    }
    return dp[i][mask] = ans;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    cout << "The cost to travelling of salesman is : " << solve(0, ((1 << n) - 1), n);

    return 0;
}