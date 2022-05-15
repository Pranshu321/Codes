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
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll lb = 1; // Stalls start from 1 only.
    ll ub = 1e9;
    ll ans = 0;
    while (lb <= ub)
    {
        ll mid = (lb + ub) / 2;
        ll cow = 1;     // We can place cow at first stall freely becasue it that there is no restriction.
        ll prev = a[0]; // We have check the distance between the stalls that it is greater and equal to the mid or the distance.
        for (ll i = 0; i < n; i++)
        {
            if (a[i] - prev >= mid)
            {
                cow++;
                prev = a[i]; // Simply update the prev element to move on and checkdistance of other stalls.
                if (cow == m)
                {
                    break;
                }
            }
        }
        if (cow == m)
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