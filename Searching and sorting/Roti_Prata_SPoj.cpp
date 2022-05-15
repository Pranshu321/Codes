#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
bool check(int a[], int n, int par, int mid)
{
    int time = 0;
    int paratha = 0;
    for (int i = 0; i < n; i++)
    {
        time = a[i]; // taking starting time for 1 paratha
        int j = 2;   // Taking j=2 because we have to increase time for second paratha and acc to question that is twice the real time (2R) and for third it is (3R).
        while (time <= mid)
        {
            paratha++;
            time = time + (a[i] * j);
            j++;
        }
        if (paratha >= par)
        {
            return true;
        }
    }
    return false;
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

        int par;
        cin >> par;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int lb = 0;   // Simply using binary search
        int ub = 1e8; // We can take the upper bound and lower bound as used here if we not able to figure out what should we take as upper and lower bound.
        int ans = 0;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (check(a, n, par, mid)) // checking That for mid time we can make paratha greater equal to the order given. Then we search for less time for minimum time...
            {
                ans = mid;
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }

        cout << "The minimum time in which we can make all parathans are: " << ans << " min";
    }

    return 0;
}