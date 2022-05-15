#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 const int N=1e5;
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
 vector<bool>vis(N,false);

 vector<int> dfs(vector<int>adj[] , int n){
     vector<int>ans;
     stack<int>s;

     s.push(0);
     vis[0]=true;
     while(!s.empty()){
         int x=s.top();
         s.pop();
        //  if(!vis[x]){
             ans.push_back(x);
            //  vis[x]=true;
        //  }

         for(auto i : adj[x]){
             if(!vis[i]){
                 s.push(i);
                 vis[i]=true;
             }
         }
     }
     return ans;
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 vector<int>adj[N];
 int n,m;
 cin>>n>>m;
 for(int i=0;i<m;i++){
 int u,v; cin>>u>>v;
 adj[u].push_back(v);
 adj[v].push_back(u);
 }

 vector<int>print=dfs(adj,n);

 for(auto i : print){
     cout<<i<<" ";
 }
 
 
 
 
return 0 ;
 
 
 } 