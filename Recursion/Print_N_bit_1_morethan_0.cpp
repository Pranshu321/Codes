#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;

 void N_bit(int one,int zero,int n,string op){
     if(n==0){
         cout<<op<<"\n";
         return;
     }
     string op1=op;
     op1.push_back('1');
     N_bit(one+1,zero,n-1,op1);

     if(one>zero){
         string op2=op;
         op2.push_back('0');
         N_bit(one,zero+1,n-1,op2);
     }
 }

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int t; cin>>t;
 while(t--){
 int n; 
 cin>>n;

 int one=0;
 int zero=0;
 string op="";
 cout<<"----------------- N_bit in which One's greater than zero's---------------\n";
 N_bit(one,zero,n,op);
 }
 
 
 
return 0 ;
 
 
 } 