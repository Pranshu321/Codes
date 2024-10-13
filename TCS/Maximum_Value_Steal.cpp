#include <bits/stdc++.h>

using namespace std;

#define int long long
vector<int> a(100);
int n = 0;

int solve(int idx)
{
    if (idx >= n)
    {
        return 0;
    }

    int y = a[idx] + solve(idx + 2);
    int x = solve(idx + 1);
    return max(x, y);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i += 1)
    {
        cin >> a[i];
    }
    int sum = solve(0);
    cout << sum;

    return 0;
}