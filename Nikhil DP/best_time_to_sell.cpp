#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int curr_buy = a[0], curr_profit = 0, max_profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < curr_buy)
        {
            curr_buy = a[i];
        }
        else if (a[i] > curr_buy)
        {
            curr_profit = a[i] - curr_buy;
        }
        max_profit = max(max_profit, curr_profit);
    }

    cout << max_profit;

    return 0;
}