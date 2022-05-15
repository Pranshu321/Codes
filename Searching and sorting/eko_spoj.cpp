#include <bits/stdc++.h>

using namespace std;

#define ll long long  int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
bool solve(long long int a[], long long int n, long long int height, long long int at_least)
{
    long long int sum = 0;
    for (long long int i = 0; i < n; i++)
    {
        if (a[i] > height)
        {
            sum += a[i] - height;
        }
    }
    if (sum >= at_least)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    long long int n, m;
    cin >> n >> m;
    long long int a[n];
    sort(a,a+n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long int lb = 0;
    long long int ub = *max_element(a, a + n);
    long long int ans = 0;
    while (lb <= ub)
    {
        long long int mid = (lb + ub) / 2;
        if (solve(a, n, mid, m))
        {
            ans = mid;
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    cout << ans;

    return 0;
}