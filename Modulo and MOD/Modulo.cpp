#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 /*
 1. (a+b)%M  = ((a%M) + (b%M))%M;
 2. (a*b)%M  = ((a%M) * (b%M))%M;
 3. (a-b)%M  = ((a%M) - (b%M) + M)%M;
 4. (a/b)%M  = ((a%M) * inverse(b) % M)%M;

 inverse of b is found by binary exponentiation.
 */
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 const int M = 1e9+7; // Integer ke range ke very close hai , and we can find multiplicative inverse from 1 to M;
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 

 
 
 
return 0 ;
 
 
 } 