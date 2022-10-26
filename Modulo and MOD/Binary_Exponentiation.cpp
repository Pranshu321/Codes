#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
// We are using divide and conquer and finding the power in this if we encounter even power we simply divide them by two and if odd we take out one and then for even power we divide again.
int binExpRecur(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    ll res = binExpRecur(a, b / 2);
    if (b & 1)
    {
        return a * (res * res) % M;
    }
    else
    {
        return (res * res) % M;
    }
}

int IterativeMethodBinExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a)%M;
        }
        a = (a * 1LL * a)%M;
        b >>= 1;
    }
    return ans;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cout << binExpRecur(2, 32) << "\n";
    cout << IterativeMethodBinExp(2, 32);

    return 0;
}