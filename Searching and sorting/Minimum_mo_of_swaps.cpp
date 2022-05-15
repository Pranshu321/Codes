#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int swaps_count(int a[], int n)
{
    vector<pair<int, int>> v;
    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (i == v[i].second)
        {
            continue;
        }
        else
        {
            swaps++;
            swap(v[i],v[v[i].second]);
            i--;
        }
    }
    return swaps;
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
    cout << "Minimum number of swaps are : " << swaps_count(a, n);

    return 0;
}