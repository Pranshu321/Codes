#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;

int fabo(int n){
    if(n==0){
        return 0;
    }
    if(n==1)
    return 0;

    if(n==2)
    return 1;

    return fabo(n-1)+fabo(n-2);
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n; cin>>n;
 cout<<fabo(n)<<" ";
 
 
 
 
return 0 ;
 
 
 } 