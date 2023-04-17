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
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int cost = 0;
    int median = 0;

    if (n % 2 != 0)
    {
        median = v[n / 2];
    }

    else
    {
        median = (v[n / 2] + v[((n + 1) / 2)]) / 2;
    }

    for (int i = 0; i < n; i++)
    {
        cost += abs(v[i] - median);
    }
    cout << cost;

    return 0;
}