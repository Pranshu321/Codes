#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 
 int countways(int n,int i,int j){
     if(i==n-1 || j==n-1){
         return 1;
     }

     if(i>=n || j>=n){
         return 0;
     }
     return (countways(n-1,i+1,j)+countways(n-1,i,j+1));
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 cout<<countways(3,0,0);
 
 
 
 
return 0 ;
 
 
 } 