#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int maximum_product(int a[], int n)
{   
    // Variables to store maximum and minimum
    // product till ith index.
    int maxval = a[0], minval = a[0];
    int maxproduct = a[0];
    int minproduct = INT16_MAX;

    for (int i = 1; i < n; i++)
    {
        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (a[i] < 0)
        {
            swap(maxval, minval);
        }
        
        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxval = max(a[i], maxval * a[i]);
        minval = min(a[i], minval * a[i]);

        maxproduct = max(maxproduct, maxval);
        minproduct = min(minproduct , minval);
    }
    cout<<minproduct;
    return maxproduct;
}

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

    cout << "The maximum product of array is : " << maximum_product(a, n);

    return 0;
}