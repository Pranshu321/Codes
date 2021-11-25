#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int ladders,snakes;
 cin>>ladders>>snakes;
 map<int,int>ladd; // using map for decreasing the time complexity for search
 map<int,int>snak;
 for(int i=0;i<ladders;i++){ // inputting ladders
     int u,v; cin>>u>>v;
     ladd[u]=v;
 }
 for(int i=0;i<snakes;i++){ // inputting snakes;
     int u,v; cin>>u>>v;
     snak[u]=v;
 }
 int moves=0;
 queue<int>q;
 q.push(1);
 vector<int>vis(101,0); // maintaning visited vector
 vis[1]=true;
 bool hundred=false; // Making check for that we have reached 100 box or not
 while(!q.empty() and !hundred){
     int siz=q.size();
     while(siz--){
         int f=q.front();
         q.pop();
      for(int dice=1;dice<=6;dice++){
          if(f+dice==100) // checking for 100 reached or not.
          hundred=true;

          if(f+dice<=100 and ladd[f+dice] and !vis[ladd[f+dice]]){ // Checking if ladder we have to marked visited and push to queue.
              vis[ladd[f+dice]]=true;
              if(ladd[f+dice]==100){
                  hundred=true;
              }
              q.push(ladd[f+dice]);
          }
          else if(f+dice<=100 and snak[f+dice] and !vis[snak[f+dice]]){ // Checking if snake present or not
              vis[snak[f+dice]]=true;
              if(snak[f+dice]==100){
                  hundred=true;
              }
              q.push(snak[f+dice]);
          }
          else if(f+dice<=100 and !vis[f+dice] and !snak[f+dice] and !ladd[f+dice]){ // For simple box with no snake and ladder
              vis[f+dice]=true;
              q.push(f+dice);
          }
      }
     }
     moves++; // Then we increase our moves.
 }
 if(hundred)
 cout<<moves<<" ";

 else
 cout<<"-1"<<" ";

 
 
 
 
return 0 ;
 
 
 } 
 /*

2 (no of ladders)    3 (no of snakes)
3 90
56 76 

(no of snakes)
99 10
30 20
20 5
 
Output : 3 

 */