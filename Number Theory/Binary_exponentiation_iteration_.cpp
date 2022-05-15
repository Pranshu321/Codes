#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 const int m=1e9+7;
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;

int Binary_iter(int a,int b){
    int res=1;
    while(b){
        if(b&1){
            res=(res* 1LL *a)%m;
        }
        a=(a* 1LL *a)%m;
        b >>=1;
    }
    return res;
}

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int a=2,b=13;
 cout<<Binary_iter(a,b);
 
 
 
 
return 0 ;
 
 
 } 