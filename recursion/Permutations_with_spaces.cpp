#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
 void Permutations_with_Spaces(string ip,string op)
   {
       if(ip.empty())
       {
           cout<<op<<"\n";
           return ;
       }
       string op1=op;
       string op2=op;
       op1.push_back(' '); // First condition we take the element with space
       op1.push_back(ip[0]); 
       
       op2.push_back(ip[0]); // Second cond. we takr the element without the space with is clearly seen by the recursive tree which we drawn.
       
       ip.erase(ip.begin()+0);
       Permutations_with_Spaces(ip,op1);
       Permutations_with_Spaces(ip,op2);
   }
   

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 string s;
 cin>>s;
 string out="";
 out.push_back(s[0]);
 s.erase(s.begin()+0);

 Permutations_with_Spaces(s,out);
 
 

 
 
 
 
return 0 ;
 
 
 } 