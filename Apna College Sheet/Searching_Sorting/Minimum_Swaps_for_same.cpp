#include <bits/stdc++.h>

using namespace std;

#define int long long

int minSwaps(int a[], int n)
{
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].first = a[i];
        arr[i].second = i;
    }
    sort(arr, arr + n);
    int ans = 0;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] or arr[i].second == i)
        {
            continue;
        }
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            // move to next node
            j = arr[j].second;
            cycle_size++;
        }

        // Update answer by adding current cycle.
        ans += (cycle_size - 1);
    }
    return ans;
}

int minSwapToMakeArraySame(int a[], int b[], int n)
{
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[b[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        b[i] = mp[a[i]];
    }

    return minSwaps(b, n);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int a[] = {3, 6, 4, 8};
    int b[] = {4, 6, 8, 3};

    int n = sizeof(a) / sizeof(int);
    cout << minSwapToMakeArraySame(a, b, n);

    return 0;
}