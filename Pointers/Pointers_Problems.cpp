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
 // Uninitialize pointer
 /*
 when the ponter dont have any address of any variable , then their is any garbagr address which may or may not belong to program.
 */
 int xx=10;
 int *p;
 p=&xx;
 *p=56;
 p=new int[4];
 *p=32; p++;
 *p=34;
 cout<<*p<<"\n";

 // Memory Leak;
 /*
 When we dont deallocate or free up the space by heap because it can arise problem of memory leak in the program.

 we should use (delete pointer_name0 for free up the memory .
 then we can point the pointer ro NULL,0 or nullptr(this is the reserve word for pointing the pointer to 0th place. ) 
 */

 // Dangling Pointer
 /*This is the case in which the pointer is pointing to the address where no storage is present , so this arises runtime error.

 If we take an example 
 void func(int *q){
     -
     ---
     -----
     --------
     delete []q;
 }

 void main(){
     int *p=new int[5];
     |
     | |
     | | |

     func(p);

     cout<<*p;
 }

 So in above program we are making heap memory which is pass to function func which is deleting the memory allocated to it . But when func done its work and main function we that p is trying access that memory which is not present at its place , which lead to dangling cond. or runtime error. 
 */ 
 
 
 
return 0 ;
 
 
 } 

 /*
 1. Uninitialize pointer
 2. memory leak
 3. dangling pointers.
 */