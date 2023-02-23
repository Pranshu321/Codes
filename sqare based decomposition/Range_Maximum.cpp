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
    int len = (int)sqrt(n) + 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> b(n, INT_MIN);
    for (int i = 0; i < n; i++)
    {
        b[i / len] = max(a[i], b[i / len]); // Array is divided into the block of len squareroot(n) and storing the max of that block this called preprocessing.
    }

    int q;
    cin >> q;
    int ans = INT_MIN;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++)
        {
            if (i % len == 0 and i + len - 1 <= r) // Checking whether we have to take full block or not. if yes simple use precompute answer.
            {
                ans = max(ans, b[i / len]);
                i += len;
            }
            else // else traverse till that index we want.
            {
                ans = max(ans, a[i]);
                i++;
            }
        }
        cout << ans << " ";
    }

    return 0;
}