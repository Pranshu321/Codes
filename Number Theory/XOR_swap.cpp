#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int a=5,b=6;
 
 a=a^b;
 
 b=b^a; // here value of a is (a^b).. so b=b^(a^b)---> b=b^b^a; ---> b=a;
 
 a=a^b; // here is a=a^b and b=a .. so a= (a^b)^a; a=a^a^b;----> a=b;

cout<<a<<" "<<b;
 
/* 
 Some Rules regarding the xor 
 1. 1^1 = 0
 2. 1^0 =1
 3. a^c^a = a^a^c; Places of element Can be interchanged
*/ 
return 0 ;
 
 
 } 