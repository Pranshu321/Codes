#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 void passing_by_value(int a,int b)
 {
     int c=a+b;
     a=c-a;
     b=c-b;
 }

 void passing_by_reference(int &a,int &b){
    
   int c=a+b;
   a=c-a;
   b=c-b;
 }
 
 void passing_by_address(int *a,int *b){
    
   int c=(*a)+(*b);
   (*a)=c-(*a);
   (*b)=c-(*b);
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
  int a=5,b=6,c,d;
  c=a;
  d=b;
 cout<<"Value of a before swapping : "<<a<<"\nValue of b before swapping : "<<b;

 passing_by_value(a,b);

 cout<<"\n\nValue of a After swapping(Value) : "<<a<<"\nValue of b after swapping : "<<b;
 
 cout<<"\n\n\nValue of a before swapping : "<<a<<"\nValue of b before swapping : "<<b;

 passing_by_reference(a,b);

 cout<<"\n\nValue of a After swapping(reference) : "<<a<<"\nValue of b after swapping : "<<b;
 
 cout<<"\n\n\nValue of a before swapping : "<<c<<"\nValue of b before swapping : "<<d;

 passing_by_address(&c,&d);

 cout<<"\n\nValue of a After swapping(address) : "<<a<<"\nValue of b after swapping : "<<b;

 
 
 
 
 
return 0 ;
 
 
 } 