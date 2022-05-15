#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
 const int V=4;
 int Triangle(int g[][V],bool directed){
     int countTriangle=0;
     for(int i=0;i<V;i++){
         for(int j=0;j<V;j++){
             for(int k=0;k<V;k++){
                 if(g[i][j] and g[j][k] and g[k][i]){
                     countTriangle++;
                 }
             }
         }
     }
     if(directed){

         return countTriangle/3;
     }
     else{
         return countTriangle/6;
     }
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int graph[][V] = { {0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}
                     };
 
    
    int digraph[][V] = { {0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}
                       };
 
    cout << "The Number of triangles in undirected graph : "
         << Triangle(graph, false);
    cout << "\n\nThe Number of triangles in directed graph : "
         << Triangle(digraph, true);
 
 
 
 
 
return 0 ;
 
 
 } 