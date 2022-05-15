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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], ones = 0;
        ;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
            {
                ones++;
            }
        }
        sort(a, a + n, greater<int>());
        for (int i = 0; i < ones; i++)
        {
            cout << "1 ";
        }

        if ((n - ones) == 2 and a[0] == 3 and a[1] == 2)
        {
            cout << "2 3"
                 << "\n";
        }
        else
        {
            for (int i = 0; i < (n - ones); i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}