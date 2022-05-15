#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
vector<vector<int>> subset(int a[], int n)
{
    int bits = 1 << n; // As we know that all subsets will be 2^n; so 1<<n shows that only.
    vector<vector<int>> ans(n);

    for (int mask = 0; mask < bits; mask++) // Traversing to all possible combination of bits.
    {
        vector<int> Set;
        for (int j = 0; j < n; j++) // traversing the array
        {
            if ((mask & (1 << j)) != 0) // Checking the bit.
            {
                Set.push_back(a[j]); // If setted enter that element.
            }
        }
        ans.push_back(Set);
    }
    return ans;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    auto ans = subset(v, n);
    for (auto i : ans)
    {
        for (auto ele : i)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}