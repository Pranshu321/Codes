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

{ // Simple two pointer approach
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        int s1 = 0, s2 = 0, i = 0, j = 0;
        int max_sum = 0;
        while (i < n && j < m)
        {
            if (a[i] < b[j]) // Here we take sum of both array before the bridge is encounter then we drcide that we have to that which sum e include for max sum and also add the bridge element , and bridge leement is the element which is same in both one.
            {
                s1 += a[i];
                i++;
            }
            else if (a[i] > b[j])
            {
                s2 += b[j];
                j++;
            }
            else
            {
                max_sum = max_sum + max(s1, s2) + a[i];
                s1 = s2 = 0; // We take sum zero as we have again again take sum from one bridge to another bridge.
                i++;
                j++;
            }
        }
        while (i < n)
        {
            s1 += a[i];
            i++;
        }
        while (j < m)
        {
            s2 += b[j];
            j++;
        }
        max_sum = max_sum + max(s1, s2); // Taking max sm if element are left over in any of array.
        cout << "The maximum sum is : " << max_sum << "\n";
    }

    return 0;
}