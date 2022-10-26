#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
 const int M = 1e18+7;
 int binMultiply(ll a , ll b){
    int ans =0;
    while(b>0){
        if(b&1){
            ans = (ans+a)%M;
        }
        a = (a+a)%M;
        b>>=1;
    }
    return ans;
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 
 
 
 
return 0 ;
 
 
 }  