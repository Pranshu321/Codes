#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int coin(int a[], int n, int val)
{
    int dp[n][val + 1];

    for (int i = 0; i <= val; i++)
    {
        dp[0][i] = (i % a[0] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= val; j++)
        {
            int NotTake = dp[i - 1][j];
            int Take = 0;
            if (a[i] <= j)
            {
                Take = dp[i][j - a[i]];
            }
            dp[i][j] = Take + NotTake;
        }
    }
    return dp[n - 1][val];
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int val;
    cin >> val;

    cout << "The ways we can archive the value is : " << coin(a, n, val);

    return 0;
}