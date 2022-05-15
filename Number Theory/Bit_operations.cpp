#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void print(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << "\n";
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int a = 13;
    int j = 3;
    print(a);

    if ((a & (1 << j)) != 0)
        cout << "set bit"
             << "\n";
    else
        cout << "unset bit\n";

    // Set bit
    print(a | (1 << 4));

    // unset bit
    print(a & ~(1 << 4));

    // Toogle bit
    print(a ^ (1 << 1));

    // Count bit
    int count = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((a & (1 << i)) != 0)
            count++;
    }
    cout << count;

    return 0;
}