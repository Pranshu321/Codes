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
 long long int dp[n+1];
 for(int i=0;i<=n;i++){
     if(i==0)
     dp[i]=0;

     else if(i==1)
     dp[i]=0;

     else if(i==2)
     dp[i]=1;

     else{
         dp[i]=dp[i-1]+dp[i-2];
     }
 }
 cout<<dp[n]<<" ";
 
 
 
 
return 0 ;
 
 
 } 