 #include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool iscycle(int src,vector<vector<int>>&adj,vector<bool> &vis,vector<int> &stack){
    stack[src]=true;
    if(!vis[src]){
        vis[src]=true;
        for(auto i:adj[src]){
            if(!vis[i] && iscycle(i,adj,vis,stack)){
                return true;
            } 
            if(stack[i]){
                return true;
            }
        }
    }
        stack[src]=false;
        return false;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
int n,m; cin>>n>>m;
vector<vector<int>>adj(n);
vector<bool>vis(n,false);
vector<int>stack(n,0);
bool cycle=false;
for(int i=0;i<m;i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
}
for(int i=0;i<n;i++){
    if(!vis[i] && iscycle(i,adj,vis,stack)){
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