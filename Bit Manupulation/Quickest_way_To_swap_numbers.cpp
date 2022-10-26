#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 

 void swapnum(int &x , int &y){
    x^=y; // x=x^y
    y^=x; // y=y^x^y toh ismai x aa jayega
    x^=y; // x=x^y^x toh ismai x aa jayega
 }
 
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int x=10,y=20;
 cout<<x<<" "<<y<<"\n";

 swapnum(x,y);

 cout<<x<<" "<<y;
 
 
 
 
return 0 ;
 
 
 } 