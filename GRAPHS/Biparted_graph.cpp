#include<bits/stdc++.h>
 
 using namespace std;
 vector<vector<int>>adj;
 vector<bool>vis;
 vector<int>col;
 bool biparted;
 #define ll long long int
 void color(int u,int curr){
   if(col[u]!=-1 && col[u]!=curr){ // it is false when the node is not colured and the color we have to give it is not of that color . 
	   biparted=false;
	   return;
   }
   col[u]=curr;
   if(vis[u])
   return;
   vis[u]=true;
   for(auto i:adj[u]){
	   color(i,curr xor 1); // curr xor 1 is the make the color different as according we want . 
   }

 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n,m; cin>>n>>m;
 biparted=true;
 adj=vector<vector<int>>(n);
 vis=vector<bool>(n,false);
 col=vector<int>(n,-1);
 
 for (int i = 0; i < m; i++)
 {   int x,y;
 cin>>x>>y;
 adj[x].push_back(y);
 adj[y].push_back(x);
	 /* code */
 }
 for(int i=0;i<n;i++){
	 if(!vis[i])
	 color(i,0);
 }
 if(biparted){
	 cout<<"Graph is biparted";
 }
 else{
	 cout<<"Graph is not bipatred";
 }
 
 
 
 
 
 
return 0 ;
 
 
 } 