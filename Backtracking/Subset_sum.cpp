#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
void subsetsum_Backtracking(int Set[], int pos, int sum, int tmpsum, int size, bool &found)
{
    if (sum == tmpsum)
        found = true;
    // generate nodes along the breadth
    for (int i = pos; i < size; i++) // Bonding Function.
    {
        if (tmpsum + Set[i] <= sum)
        {
            tmpsum += Set[i];
            // consider next level node (along depth)
            subsetsum_Backtracking(Set, i + 1, sum, tmpsum, size, found);
            tmpsum -= Set[i];
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
    int sum;
    cin >> sum;
    bool found = false;
    subsetsum_Backtracking(a, 0, sum, 0, n, found);

    if (found)
        cout << "Yes sum is present";

    else
    {
        cout << "Sum is not present";
    }

    return 0;
}