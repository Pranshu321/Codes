#include <bits/stdc++.h>

using namespace std;

#define ll long long int
/*The game is simple. You initially have ‘H’ amount of health and ‘A’ amount of armor. At any instant you can live in any of the three places - fire, water and air. After every unit time, you have to change your place of living. For example if you are currently living at fire, you can either step into water or air.

1. If you step into air, your health increases by 3 and your armor increases by 2

2. If you step into water, your health decreases by 5 and your armor decreases by 10

3. If you step into fire, your health decreases by 20 and your armor increases by 5

-----> If your health or armor becomes <=0, you will die instantly

Find the maximum time you can survive.*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int dp[1001][1001];

int Moving(int h, int a, int way)
{
    if (h <= 0 or a <= 0)
    {
        return 0;
    }
    if (dp[h][a] != -1)
    {
        return dp[h][a];
    }
    int x, y, z;
    x = y = z = 0;
    if (way != 1)
    {
        x = 1 + Moving(h + 3, a + 2, 1); // Taking the case when we move to 1 or we say air.
    }
    if (way != 2)
    {
        y = 1 + Moving(h - 5, a - 10, 2); // Taking the case when we move to 1 or we say water.
    }
    if (way != 3)
    {
        z = 1 + Moving(h - 20, a + 5, 3); // Taking the case when we move to 1 or we say fire.
    }

    return dp[h][a] = max({x, y, z});
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int h, a;
        cin >> h >> a;

        memset(dp, -1, sizeof(dp)); // Initializaing the dp by -1

        cout << max({Moving(h + 3, a + 2, 1), Moving(h - 5, a - 10, 2), Moving(h - 20, a + 5, 3)}) << "\n";
    }

    return 0;
}