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
    {
        cin >> a[i];
    }
    int ans = 1, curr = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] <= a[i])
            curr++;
        else
            curr = 0;
        ans = max(ans, curr);
    }
    cout << ans+1;

    return 0;
}