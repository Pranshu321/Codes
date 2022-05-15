#include <bits/stdc++.h>

using namespace std;
/* Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum should be greater than the sum of rest of the elements of the array.*/
// In this we simply first take sum of array and then sort the srray , we will maintain pointer from end and starting subtracting it from sum and adding it to answer , and when the answer value is greater than the sum , then we return the value of i which will denote the length of smallest subset.
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
    sort(a, a + n);
    int i = 0;
    int j = n - 1;
    int sum = accumulate(a, a + n, 0);
    int ans = 0;
    while (true)
    {
        ans += a[j];
        sum -= a[j];
        i++;
        if (ans > sum)
        {
            break;
        }
    }
    cout << "The minimum length of subset will be : " << i;

    return 0;
}