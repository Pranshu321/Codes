#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void subset_sum(int idx, int sum, int a[], int n)
{
    if (idx == n)
    {
        cout << sum << " ";
        return;
    }

    // taking the number into sum
    subset_sum(idx + 1, sum + a[idx], a, n);

    // Not taking into sum
    subset_sum(idx + 1, sum, a, n);
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

    subset_sum(0, 0, a, n);

    return 0;
}