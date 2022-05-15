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
    // Upper bound is binary search and return the next index.
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = false;
    int x;
    cin >> x;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int y = a[i] + x;
        int ans = upper_bound(a + i + 1, a + n, y) - a - 1;
        if (a[ans] - a[i] == x)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "YES PRESENT";
    }
    else
    {
        cout << "NOT PRESENT";
    }

    return 0;
}