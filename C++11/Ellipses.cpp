#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 

int sum(int n,...)
{
 va_list list;
 va_start(list,n);
 int x;
 int sum=0;
 for(int i=0;i<n;i++)
{
 sum+=va_arg(list,int);
}
 return sum;
}


 int main () 
 { 
 cout<<sum(3,10,20,30)<<endl;
 cout<<sum(5,1,2,3,4,5)<<endl;

 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 
 
 
 
 return 0 ;
 
 
} 