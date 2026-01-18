#include <bits/stdc++.h>

using namespace std;

#define int long long

void dfs(int node, vector<int> adj[], vector<bool>&visited) {
    visited[node] = true;
    cout << node << " ";
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, adj, visited);
        }
    }

}
void dfs_iter(int node, vector<int> adj[], vector<bool>visited) {
    stack<int>s;
    s.push(node);
    visited[node]=true;
    while(!s.empty()){
        auto x = s.top(); s.pop();
        cout<<x<<" ";
        for(auto i : adj[x]){
            if(!visited[i]){
                s.push(i);
                visited[i]=true;
            }
        }
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n=4;
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool>vis(n, false);
        dfs(0, adj, vis);
        vector<bool> visi(n, false);
        dfs_iter(0, adj, visi);

    return 0;
}