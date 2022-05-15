#include<bits/stdc++.h>
 
 using namespace std;
 const int N=1e4;
 const int INF=1e7;
 #define ll long long int
 vector<int>dist(N,INF);
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 int Solve(int src,int dest,vector<pair<int,int>>g[]){
     set<pair<int,int>>s;
     dist[src]=0;
     s.insert({0,src});
     while(!s.empty()){
         auto x=*(s.begin());
         s.erase(x);
         for(auto it : g[x.second]){
             if(dist[it.first]>dist[x.second]+it.second){ // if dist of node u is greater than adding the dist of saved node and sum of the weight to other niode.  
        s.erase({dist[it.first],it.first}); // then erase it and update
        dist[it.first]=dist[x.second]+it.second; // update dist
        s.insert({dist[it.first],it.first}); // reenter the dist
        }
         }
     }
     if(dist[dest]==INF){
         return -1;
     }
     else
     return dist[dest];
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n,m; cin>>n>>m;
 vector<pair<int,int>>g[n];
 for(int i=0;i<m;i++){
     int u,v;
     cin>>u>>v;
     g[u].push_back({v,0});
     g[v].push_back({u,1});
 }

 cout<<"The minimum reverse nodes are : "<<Solve(0,6,g);
 
 
 
 
return 0 ;
 
 
 } 