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
 int n; cin>>n;
 int ans=0;
 for(int i=0;i<300;i+=3){
     if(i>=n){
      ans=i;
      break;
     }
 }

 cout<<ans-n;
 
 
 
 
return 0 ;
 
 
 } 