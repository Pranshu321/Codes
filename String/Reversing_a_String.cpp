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
    string s;
    cin >> s;

    int j = s.length() - 1;
    for (int i = 0; i < j; i++, j--)
    {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    cout << s;

    return 0;
}