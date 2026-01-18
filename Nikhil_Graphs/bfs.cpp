#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n = 4;
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n, false);

    queue<int>q;
    q.push(0);
    vis[0]=true;
    while(!q.empty()){
        auto x=q.front();
        cout<<x<<" ";
        q.pop();
        for(auto i : adj[x]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
            }
        }
    }

    return 0;
}