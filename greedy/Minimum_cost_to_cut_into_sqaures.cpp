#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    m--;
    n--;
    int x[m], y[n];
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }

    // here we are sorting in decending order because we take first the more cost one cutes because the peices are less to it compensates that , and at the end the more peices cuts will compensates with the less price one.
    sort(x, x + m, greater<int>());
    sort(y, y + n, greater<int>());

    // And another main point is that if we cut the vertical cut then the no of peices of horizontal increses so for each verticle cut we have to increase horizontal cuts.
    int horizontal_count = 1;
    int vertical_count = 1;
    int ans = 0, i = 0, j = 0;
    while (i < m && j < n)
    {
        if (x[i] > y[j])
        { // here checking the vertical cuts;
            ans += x[i] * vertical_count;
            horizontal_count++;
            i++;
        }
        else
        {
            ans += y[j] * horizontal_count;
            vertical_count++;
            j++;
        }
    }

    while (i < m)
    {
        ans += x[i] * vertical_count;
        i++;
    }

    while (j < n)
    {
        ans += y[j] * horizontal_count;
        j++;
    }

    cout << "The minimum cost required to cut into sqares : " << ans;

    return 0;
}