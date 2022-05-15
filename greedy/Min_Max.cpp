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
    int n, k; // K gives the value that the atmost candies wil be should get when we buy one candy.
    cin >> n >> k;
    int candies[n];
    for (int i = 0; i < n; i++)
    {
        cin >> candies[i];
    }
    int maxi = 0, mini = 0;
    int i = 0, j = n - 1;

    sort(candies, candies + n); // Sorting the array
    while (i <= j)
    {
        mini += candies[i]; // Due to sorting inascending order the minimum value is at starting so , buying starting candy will giving minimum money want to buy candies
        i++;
        j = j - k; // this is that the candies which we will get in free after buying one candy and buy from last to as the large value is at last , so we take them for free..
    }
    sort(candies, candies + n, greater<int>());
    i = 0;
    j = n - 1;
    while (i <= j)
    {
        maxi += candies[i];
        i++;
        j = j - k;
    }

    cout << "The Max Value from we can buy candies : " << maxi << "\n";
    cout << "The Min Value from we can buy candies : " << mini;

    return 0;
}