#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

int celebrity(vector<vector<int>> &a, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i][j] == 1)
        { // This means ith person knows jth person , so ith will be candidate celebrity.
            i++;
        }
        else
        {
            j--;
        }
    }

    int candidate = i;

    for (int k = 0; k < n; k++)
    {
        // Now, all that is left is to check that whether
        // the candidate is actually a celebrity i.e: he is
        // known by everyone but he knows no one
        if (k != candidate)
            if (a[candidate][k] == 1 || a[k][candidate] == 0)
            { // here the case when candidate dont know i , but i knows candidate in that case our assumption will be wrong.
                return -1;
            }
    }
    return candidate;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }

    cout << "The index of Celebrity is : " << celebrity(v, n);

    return 0;
}