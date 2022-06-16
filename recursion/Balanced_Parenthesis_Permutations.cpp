#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 
 void solve(int open,int close,vector<string>&v,string op){
     if(open==0 && close==0){
         v.push_back(op);
         return;
     }
     if(open!=0){ // We can take open barackets till it present.
         string op1=op;
         op1.push_back('(');
         solve(open-1,close,v,op1);
     }
     if(close>open){ // But their is condition on closed as we take it , when there extra open open bracket so to close it or we can say to make it balanced we want closed ........... eg:- ()( in this we want close bracket and number of close bracket is more than open. [Intial open and close bracket :- 3 , 3] ........[After above experssion :- 1 , 2]
        //  string op1=op;
         string op2=op;
         op2.push_back(')');
         solve(open,close-1,v,op2);

     }
 }

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n;
 cin>>n;

 int open=n;
 int close=n;
 string op="";
 vector<string>v;
 cout<<"------------------ Balanced Parenthesis----------------------\n";
 solve(open,close,v,op);
 for(auto i : v){
     cout<<i<<"\n";
 }
 
 
 
return 0 ;
 
 
 } 