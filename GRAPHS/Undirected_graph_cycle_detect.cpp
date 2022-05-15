#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool iscycle(int src,vector<vector<int>>&adj,vector<bool> &vis,int parent){
    vis[src]=true;
    for(auto i:adj[src]){
        if(i!=parent){
            if(vis[i])
            return true;
            if(!vis[i] && iscycle(i,adj,vis,src))
            return true;
        }
    }
    return false;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
int n,m; cin>>n>>m;
vector<vector<int>>adj(n);
vector<bool>vis(n,false);
bool cycle=false;
for(int i=0;i<m;i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
for(int i=0;i<n;i++){
    if(!vis[i] && iscycle(i,adj,vis,-1)){
        cycle=true;
    }
}
	if(cycle){
	    cout<<"Cycle is present"<<"\n";}
	    else{
	        cout<<"Cycle is not present";
	    }
	
	return 0;
}