#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void subset_sum(int idx, int a[], vector<int> &temp, vector<vector<int>> &ans, int n, int target)
{

    if (target == 0) // if target==0  to break condition
    {
        ans.push_back(temp);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (i > idx && a[i] == a[i - 1]) // Same element is to not allowed in a subset so this cond.
        {
            continue;
        }

        if (a[i] <= target) // If the elemnt is less than target
        {
            temp.push_back(a[i]);
            subset_sum(i + 1, a, temp, ans, n, target - a[i]);
            temp.pop_back();
        }
    }
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
    int k;
    cin >> k;
    vector<int> temp;
    vector<vector<int>> ans;
    subset_sum(0, a, temp, ans, n, k);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}