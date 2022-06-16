#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
vector<vector<int>> generate(int n)
{
    vector<vector<int>> ans(n);
    if (n == 1)
    {
        return {{1}};
    }
    ans[0] = {1};
    ans[1] = {1, 1};

    if (n == 2)
    {
        return ans;
    }

    for (int i = 3; i <= n; i++)
    {
        vector<int> in(i, 1);
        for (int j = 1; j < i - 1; j++)
        {
            in[j] = ans[i - 2][j - 1] + ans[i - 2][j];
        }
        ans[i - 1] = in;
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

    vector<vector<int>> pascal = generate(n);

    for (auto i : pascal)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}