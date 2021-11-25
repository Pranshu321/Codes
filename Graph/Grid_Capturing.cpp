#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 void change(vector<vector<char>>&a, int x,int y){
     a[x][y]='*';
     int dx[]={0,0,-1,1};
     int dy[]={1,-1,0,0};
     for(int i=0;i<4;i++){
         int cx=x+dx[i];
         int cy=y+dy[i];
         if(cx>=0 and cx<a.size() and cy>=0 and cy<a[0].size() and a[cx][cy]=='O'){ // CHECKING THAT CX AND CY ARE IN BOUND OR NOT IF IN BOUND CHNAGE THE BIT OR CHARATER
             change(a,cx,cy); 
         }
     }
 } 
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n,m;
 cin>>n>>m;
 vector<vector<char>>graph(n,vector<char>(m));
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         cin>>graph[i][j];
     }
 }
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(i==0 || i==n-1 or j==0 or j==m-1){
             if(graph[i][j]=='O')
             change(graph,i,j);
         }
     }
 }
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(graph[i][j]=='O'){
             graph[i][j]='X';
         }
     }
 }
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(graph[i][j]=='*'){
             graph[i][j]='O';
         }
     }
 }

 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         cout<<graph[i][j]<<" ";
     }
     cout<<endl;
 }
 
 
 
 
return 0 ;
 
 
 } 

 /*
4 4
X X X X
X O O X
X X O X
X O X X

OUTPUT : 
X X X X 
X X X X
X X X X
X O X X

 */