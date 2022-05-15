#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
vector<vector<int>> mergeIntervals(vector<vector<int>> &a)
{
    // Write your code here.
    vector<vector<int>> mergedIntervals;
    if (a.size() == 0)
    {
        return mergedIntervals;
    }
    sort(a.begin(), a.end());
    vector<int> temp = a[0];

    for (auto i : a)
    {
        if (i[0] <= temp[1])
        {
            temp[1] = max(temp[1], i[1]);
        }
        else
        {
            mergedIntervals.push_back(temp);
            temp = i;
        }
    }
    mergedIntervals.push_back(temp);
    return mergedIntervals;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<vector<int>> matrix;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < 2; j++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        matrix.push_back(v);
    }
    cout << "\n Merged Intervals are : -----------\n";
    vector<vector<int>> ans = mergeIntervals(matrix);
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