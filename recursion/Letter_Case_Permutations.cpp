#include<bits/stdc++.h>
 
 using namespace std;
 // In this we have print all permutaions of a1b2 which alphanumeric so we take care of all the permutations will be [a1b2,A1b2,a1B2,A1B2];
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 
 void Letter_Case(string ip,string op,vector<string>&v){
     if(ip.empty()){
         v.push_back(op);
         return;
     }
     if(isalpha(ip[0])){ // Case 1 when the element is alphabet.
         string op1=op;
         string op2=op;
         // Two choices that we have............
         op1.push_back(tolower(ip[0])); // First that we take lower case of alpha.
         op2.push_back(toupper(ip[0])); // Second case that we take upper case of alpha.
         ip.erase(ip.begin()+0);
         Letter_Case(ip,op1,v);
         Letter_Case(ip,op2,v);
     }
     else{ // Case when element is number.
         string op1=op; 
         op1.push_back(ip[0]); // Only one choice that we have add it.
         ip.erase(ip.begin()+0);
         Letter_Case(ip,op1,v);
     }
 }

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 string ip;
 cin>>ip;
 string op="";
 vector<string>v;

 Letter_Case(ip,op,v);
 cout<<"--------------Letter Case-------------\n";
 for(auto i : v){
     cout<<i<<"\n";
 }
 
 
 
 
return 0 ;
 
 
 } 