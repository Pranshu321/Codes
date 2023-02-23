#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int count = 0;
    vector<int> adj[n];
    vector<int> iddeg(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        iddeg[v]++; // keeping the of indegree of each node .
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (iddeg[i] == 0) // putting the element which is having the idegree equal to 0
            q.push(i);
    }
    while (!q.empty())
    {
        count++;
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto i : adj[x])
        {
            iddeg[i] = iddeg[i] - 1;
            if (iddeg[i] == 0)
            {
                q.push(i);
            }
        }
    }

    return 0;
}

/* 6 6
5 2
5 0
4 0
4 1
2 3
3 1 */