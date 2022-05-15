#include <bits/stdc++.h>

using namespace std;

#define ll long long int
// Question Link :- https://docs.google.com/document/d/1zuw8hBXHsiTYTH8u986fQhn8TWfpOk9BQBIRH3lo_W8/edit
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int cost[1001][1001];
int dp[21][(1 << 21)];
// dp;
int solve(int i, int mask, int n)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][mask] != -1)
    {
        return dp[i][mask];
    }
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))                                                 // Here checking that jth bit is on or not.
            ans = min(ans, cost[j][i] + solve(i + 1, (mask ^ (1 << j)), n)); // If jth bit is on then we recusive call that call so that we consider it as the answer and add the cost also turn off that bit and start checking for next job assingment.
    }
    return dp[i][mask] = ans; // Saving the solution or we say saving recursive call,
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

    cout << "The minmum cost is : " << solve(0, ((1 << n) - 1), n);

    return 0;
}