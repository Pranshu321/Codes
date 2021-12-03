#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 

 void bubble_Sort(int a[],int n){
     for(int i=0;i<n-1;i++){
         for(int j=0;j<n-i-1;j++){
             if(a[j]>a[j+1]){
                 swap(a[j],a[j+1]);
             }
         }
     }
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int a[]={7,5,3,2,4,6};
 int n=6;

 bubble_Sort(a,n);
 for(auto i:a){
     cout<<i<<" ";
 }
 
 
 
 
return 0 ;
 
 
 } 