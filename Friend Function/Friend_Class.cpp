#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 
 class my{
     int a;
     protected:
     int b;
     public:
     int c;

     friend class your;
 };

 class your{
     
     my m;

     void func(){
         m.a=10;
         m.b=23;
         m.c=98;
     }
 };
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 
 
 
 
return 0 ;
 
 
 } 