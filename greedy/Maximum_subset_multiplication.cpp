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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int zero_count = 0;
    int negative_count = 0;
    int product = 1;
    int max_neg = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zero_count++;
            continue;
        }
        if (a[i] < 0)
        {
            negative_count++;
            max_neg = max(a[i], max_neg); // mainting the maximum negative number to minus that if the count became it will degrade our max output. (and the maximum element will be considered as the negative element is maximum decided here -1 is maximum one.)
        }
        product *= a[i];
    }
    if (zero_count == n)
    {
        cout << 0;
        return 0;
    }
    else if (negative_count == 1 and zero_count + negative_count == n)
    {
        cout << 0;
        return 0;
    }
    else if (negative_count % 2 != 0)
    {
        product = product / max_neg;
    }
    cout << max_neg << " ";
    cout << product;

    return 0;
}