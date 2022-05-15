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
 int x=10;
 float y=3.4;

 decltype(y) z=12.3;

 auto ans=x*y+z;
 cout<<ans<<" ";
 
 
 
 
 return 0 ;
 
 
 } 