#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int

 namespace first{
 void func(){
     cout<<"First\n";
 }
 };

 namespace Second{
 void func(){
     cout<<"Second\n";
 }
 };
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;

//  using namespace first;
 using namespace Second;
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 func();
//  Second::func();
 
 
 
return 0 ;
 
 
 } 