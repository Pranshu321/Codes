#include <bits/stdc++.h>

using namespace std;
// Searching in an array where adjacent differ by at most k
/*A step array is an array of integers where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence of the key.*/
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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x, k;
    cin >> x >> k;
    int ans = -1;
    int i = 0;
    while (i < n)
    {
        if (a[i] == x)
        {
            ans = i + 1;
        }
        i += max(1, (abs(a[i] - x) / 2)); // This is main step in which we increament i stargitically that it will increase in interval that as we that element aleays differ by k , not greater than that . So we can find the steps at which we find element so we find by this (diff between current element and finding element)/k (as it differ by k);
    }

    cout << "The element is present at position : " << ans;

    return 0;
}