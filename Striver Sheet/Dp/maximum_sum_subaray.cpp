#include <bits/stdc++.h>

using namespace std;
#define inf 999999
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

int maximum_sum(int arr[], int n)
{
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
        dp[i] = arr[i];
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {

                temp = max(temp, dp[j]);
            }
        }
        dp[i] += temp;
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<inf;)

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "The maximum product of array is : " << maximum_sum(a, n);

    return 0;
}