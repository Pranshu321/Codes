#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n=4;
    vector<vector<int>>adj(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x-1][y-1]=1;
        adj[y-1][x-1]=1;
    }

    for(auto i : adj){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }

    /*
    Pros:
    - Simple Structure
    - Efficient for dense graph
    - quick edge queries

    Cons:
    - Space complexity
    - expensive operations, not suitable for dynamic graphs
    - memeory expensive
    */

    return 0;
}