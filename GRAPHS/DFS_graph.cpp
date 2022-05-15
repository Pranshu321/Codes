#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>adj[1000];
bool vis[1000];
void dfs(int node){
   //preorder
    vis[node]=1;
    cout<<node<<" ";
    vector<int>::iterator it;
    //inorder
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(vis[*it]){}
        else{
            dfs(*it);
        }
    }
    //postorder
    // cout<<node<<" ";
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
    int n,m; cin>>n>>m;
    // vector<int>adj[n];
for(int i=0;i<1000;i++){
    vis[i]=0;
}
int x,y;
for(int i=0;i<m;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
dfs(1);
	
	return 0;
}
// 7 7
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 7 3
// output prerder:1 2 4 5 6 7 3 
//postorder:4 5 6 3 7 2 1 