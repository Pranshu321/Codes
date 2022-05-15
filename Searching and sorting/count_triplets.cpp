#include <bits/stdc++.h>

using namespace std;
// Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.
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
    int s;
    cin >> s;
    sort(a, a + n);
    int count = 0;
    for (int k = 0; k < n - 2; k++)
    {
        int i = k + 1; // Starting Pointer
        int j = n - 1; // End Pointers
        while (i < j)
        {
            int sum = a[i] + a[j] + a[k];
            if (sum < s)
            {
                count += (j - i); // As we have find the element which by adding have the sum less than that is given so all other element less than it will lead to our answer.
                i++;
            }
            else
            {
                j--;
            }
        }
    }

    cout << "The number of triplets : " << count;

    return 0;
}