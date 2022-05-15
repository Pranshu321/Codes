#include <bits/stdc++.h>

using namespace std;
// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
vector<int> finding(int a[], int n)
{
    int x, y;
    for (int i = 0; i < n; i++)
    {
        if (a[abs(a[i]) - 1] < 0) // This is when element is visited second time so this means thta it is repeatetive.
        {
            x = abs(a[i]);
        }
        else
        {
            a[abs(a[i]) - 1] = -a[abs(a[i]) - 1]; // When visiting element first time so we mark it negative so that we able to know that it is visited.
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0) // And we know that the element which is position that is not visited so , its index will not called in array so missing element will be index+1; 
        {
            y = i + 1;
        }
    }
    return {x, y};
}
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
    vector<int> v = finding(a, n);
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
            cout << "The repeated element is : " << v[i];
        else
        {
            cout << "\nThe missing element is : " << v[i];
        }
    }

    return 0;
}