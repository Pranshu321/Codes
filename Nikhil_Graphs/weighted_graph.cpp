#include <bits/stdc++.h>

using namespace std;

#define int long long

struct GraphNode
{
    int v;
    int weight;
    GraphNode(int _v, int _weight)
    {
        v = _v;
        weight = _weight;
    }
};

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n = 4;
    vector<vector<GraphNode*>> adj(n);
    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        auto x = new GraphNode(v,w);
        adj[u].push_back(x);
    }
    for(auto i : adj[0]){
        cout<<i->v<<" "<<i->weight;
    }

    return 0;
}