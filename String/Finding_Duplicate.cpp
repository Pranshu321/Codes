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
    int a[25] = {0};
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        a[s[i] - 'a']++;
    }

    for (int i = 0; i < 25; i++)
    {
        if (a[i] > 0)
        {
            cout << (char('a' + i)) << " "
                 << "present " << a[i] << " times\n";
        }
    }

    return 0;
}