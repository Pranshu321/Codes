#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 const int N=1e5+10;
 const int MOD=1e7;
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
int dp[N]; 

int MNOS(int n){
    if(n==1 || n==0 || n==2 || n==3){
        return n;
    }

    if(dp[n]!=MOD){
        return dp[n];
    }

    for(int i=1;i*i<=n;i++){
        dp[n]=min(dp[n],1+MNOS(n-i*i));
    }

    return dp[n];
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n; cin>>n;
for(int i=0;i<N;i++){
    dp[i]=MOD;
}

cout<<MNOS(n);

 
 
 
 
return 0 ;
 
 
 } 