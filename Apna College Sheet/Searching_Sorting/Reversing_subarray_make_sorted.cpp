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
    vector<int> a(n);
    int x = -1;
    int y = -1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            if (x == -1)
            {
                x = i;
            }
            y = i + 1;
        }
    }
    bool flag = true;
    reverse(a.begin() + x, a.begin() + y + 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            cout << "False";
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "True";

    return 0;
}