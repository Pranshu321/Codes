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
    if (idx == n)
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }

    if (a[idx] <= target)
    {
        temp.push_back(a[idx]);
        subset_sum(idx, a, temp, ans, n, target - a[idx]);
        temp.pop_back();
    }

    subset_sum(idx + 1, a, temp, ans, n, target);
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