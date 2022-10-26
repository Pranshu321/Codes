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

    cout << __builtin_clz(5) << "\n";      // It counts number of zeros before the first occurrence of one(set bit).__builtin_clzll(x) for long and long long data types.
    cout << __builtin_ctz(10) << "\n";      // Count no of zeros from last to first occurrence of one(set bit). __builtin_ctzll(x) for long and long long data types.
    cout << __builtin_popcount(5) << "\n"; // Count Number of ones.

    cout<<__builtin_parity(11); // Number of ones is odd then odd parity otherwise even parity.

    // 1001
    return 0;
}