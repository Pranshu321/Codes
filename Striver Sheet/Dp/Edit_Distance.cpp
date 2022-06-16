#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int solve(string a, string b, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int edit = dp[i - 1][j - 1];
            int ins = 1 + dp[i][j - 1];
            int del = 1 + dp[i - 1][j];

            if (a[i - 1] != b[j - 1])
            {
                edit++;
            }
            dp[i][j] = min({edit, ins, del});
        }
    }
    return dp[n][m];
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();

    cout << "The total no of insertion , deletion or edit is : " << solve(a, b, n, m);

    return 0;
}