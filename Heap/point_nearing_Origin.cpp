#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<pair<int, int>> v;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 0; i < n; i++)
    {
        pq.push({(v[i].first ^ 2 + v[i].second ^ 2), {v[i].first, v[i].second}});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        cout << pq.top().second.first << " " << pq.top().second.second << "\n";
        pq.pop();
    }
    return 0;
}