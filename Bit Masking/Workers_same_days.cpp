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
    int total_workers;
    cin >> total_workers;
    vector<int> masks(total_workers, 0);
    for (int i = 0; i < total_workers; i++)
    {
        int mask = 0;
        int total_days;
        cin >> total_days;
        for (int j = 0; j < total_days; j++)
        {
            int day;
            cin >> day;
            mask = (mask | (1 << day)); // Creating a Mask
        }
        masks[i] = mask; // Saving that mask
    }
    int max_days_common = 0;
    int person1 = 0;
    int person2 = 0;
    for (int i = 0; i < total_workers; i++)
    {
        for (int j = i + 1; j < total_workers; j++)
        {
            int intersection_of_days = masks[i] & masks[j]; // Filtering the same days or we say at same position which the bits are setted .
            int common_days = __builtin_popcount(intersection_of_days);
            if (common_days > max_days_common)
            {
                person1 = i;
                person2 = j;
                max_days_common = max(max_days_common, common_days);
            }
        }
    }
    cout << person1 + 1 << " " << person2 + 1 << " " << max_days_common;

    return 0;
}