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
    int k;
    cin >> k;

    int arr[n];
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    int ans = 0;

    while (k--)
    {
        int x = pq.top();
        pq.pop();
        pq.push(floor(x / 2));
    }

    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}