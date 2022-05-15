#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
bool check(int p, int n)
{
    int temp = p, count = 0, incre = 5;
    while (incre <= temp)
    {
        count += temp / incre;
        incre = incre * 5;
    }
    return (count >= n);
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "The Factorial for which the trailing zeroes number same as given " << 5;
        return 0;
    }
    int low = 0;
    int high = 5 * n;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (check(mid, n))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "The Factorial for which the trailing zeroes number same as given " << low << " ";

    return 0;
}