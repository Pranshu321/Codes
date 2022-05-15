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
 string main="apnanainknaruto";
 string sub="na";
 int count=0;
 int n=main.size(),m=sub.size();
 for(int i=0;i<n-m+1;i++){
     if(main.substr(i,m)==sub){
         count++;
     }

 }
 cout<<count<<" ";
 
 
 
 
return 0 ;
 
 
 } 