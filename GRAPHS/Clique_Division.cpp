#include<bits/stdc++.h>
 
 using namespace std;
 int flag=0; 
 #define ll long long int
 //A Clique is a subgraph of graph such that all vertices in subgraph are completely connected with each other. Given a Graph, find if it can be divided into two Cliques.
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 
 void biparted(int src,int parent,int col,vector<int>&color,vector<int>g[]){
     color[src]=col;
     for(auto i : g[src]){
         if(!color[i]){
             biparted(i,src,3-col,color,g);
         }
         else if(i!=parent && col==color[i]){
             flag=1;
             break;
         }
     }
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n,m;
 cin>>n>>m;
 vector<int>g[n];
 vector<int>color(n,0);
 vector<int>dummy(n,0);
 vector<int>reverse[n];
 for(int i=0;i<m;i++){
     int u,v;
     cin>>u>>v;
     g[u].push_back(v);
     g[v].push_back(u);
 }
 
 for(int i=0;i<n;i++){
     dummy[i]=1;
     for(auto j : g[i]){
         dummy[j]=1;
     }

     for(int k=0;k<n;k++){
         if(dummy[k]==0){
             reverse[i].push_back(k);
             reverse[k].push_back(i);
         }
     }
     dummy.clear();

 }
 biparted(0,0,1,color,reverse);
 if(!flag)
  cout<<"Two Clique Possible";
  else
  cout<<"Two clique not possible";
 

 
 
 
 
return 0 ;
 
 
 } 