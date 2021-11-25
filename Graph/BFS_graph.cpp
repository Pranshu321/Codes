#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
vector<int>adj[1000]; //vector of array  
    vector<int>::iterator it;
bool vis[1000];
int n,m; cin>>n>>m;
for(int i=0;i<1000;i++){
    vis[i]=0;
}
for(int i=0;i<m;i++){
    int x,y; cin>>x>>y; 
    adj[x].push_back(y);
    adj[y].push_back(x);
}
queue<int>q; // BFS breadth First serach
// it=adj[0].begin();
q.push(1); // push first node type;
vis[1]=true;
while(!q.empty()){
    int node=q.front();
    q.pop();
    cout<<node<<"\n";
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            vis[*it]=true;
            q.push(*it);
        }
    }
}

	
	return 0;
}