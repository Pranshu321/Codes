#include<bits/stdc++.h>
 
 using namespace std;
 const int m=1e9+7;
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
int power(int a,int b){
    if(b==0)
    return 1;
    ll res=power(a,b/2);
    if(1&b){
        return (a*(res*res)%m)%m;
    }
    else
    return (res*res)%m;
}

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int a=2,b=3;
//  cin>>a>>b;
 cout<<pow(a,b)<<"\n";
 cout<<power(a,b);
 
 
 
 
return 0 ;
 
 
 } 
 