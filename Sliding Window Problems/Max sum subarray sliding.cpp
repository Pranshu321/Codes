#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void Max_Sum_SubArray(int a[], int n, int k, int x)
{
    int sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    if (sum < x)
    {
        ans = sum;
    }
    for (int i = k; i < n; i++)
    {
        sum = sum - a[i - k]; // starting index minus
        sum = sum + a[i];     // adding next index
        if (sum < x)
        {
            ans = max(sum, ans);
        }
    }
    cout << ans << "\n";
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int a[] = {7, 5, 4, 6, 8, 9};
    Max_Sum_SubArray(a, 6, 3, 20);

    return 0;
}