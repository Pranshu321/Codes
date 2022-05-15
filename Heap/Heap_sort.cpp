#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 
 void heapify(vector<int>&v,int n,int i){
     int max_idx=i;
     int l=2*i+1;
     int r=2*i+2;

     if(l<n && v[l]>v[max_idx]){
         max_idx=l;
     }
     if(r<n && v[r]>v[max_idx]){
         max_idx=r;
     }

     if(max_idx!=i){
         swap(v[i],v[max_idx]);

         heapify(v,n,max_idx);

     }
 }


 void heap_Sort(vector<int>&v,int n){

     for(int i=(n/2)-1;i>=0;i--){
         heapify(v,n,i);
     }

     for(int i=n-1;i>0;i--){
         swap(v[0],v[i]);
         heapify(v,i,0);
     }

 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n;
 cin>>n;

 vector<int>a(n);

 for(int i=0;i<n;i++){
     cin>>a[i];
 }
  
 heap_Sort(a,n);
 
 for(int i=0;i<n;i++){
     cout<<a[i]<<" ";
 }
return 0 ;
 
 
 } 