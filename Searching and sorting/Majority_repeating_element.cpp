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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 1, me = a[0]; // Here we are using the thing like kadane algorithm.
    for (int i = 1; i < n; i++)
    {
        if (a[i] == me) // here count element if its succssor is equal to it and if not decreament , this will give most accurate element that may be our answer.
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            me = a[i];
            count = 1;
        }
    }
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == me)
        {
            counter++;
        }
    }
    if (counter > (n / 2))
    {
        cout << "The max repeating element is : " << me;
    }
    else
    {
        cout << "No element found repeating greater than the (n/2) times";
    }

    return 0;
}