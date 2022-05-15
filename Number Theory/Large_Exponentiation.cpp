#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 const long long m=1e18+7;
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;

int bin_multi(long long a,long long b){
    int ans=0;
while(b>0){
    if(b&1){
        ans=(ans+a)%m;
    }
    a=(a+a)%m;
    b >>=1;
}
    return ans;
}
int Large_expo(long long a,long long b){  // same as the above function we are doing addition as it lead to multiplication.
  int ans=1;
  while(b>0){
      if(b&1){
          ans=bin_multi(ans,a);
      }
      a=bin_multi(a,a);
      b >>=1;

  }
  return ans;
}


 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 ll a=2,b=3;
 cout<<Large_expo(a,b);
 
 
 
 
return 0 ;
 
 
 } 