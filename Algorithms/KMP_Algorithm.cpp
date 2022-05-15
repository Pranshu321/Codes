#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 

vector<int> prefix_calculation(string s){
    int n=s.size();
    vector<int> pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];

        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
    return pi;
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 string s="na";
 string t="apnacollege";
 vector<int>prefix=prefix_calculation(s);
 for(auto i:prefix){
     cout<<i<<" ";
 }
 cout<<"\n";
 int pos=-1;
 int i=0,j=0;
 while(i<t.size()){
     if(t[i]==s[j]){
         i++;
         j++;
     }
     else{
         if(j!=0){
             j=prefix[j-1];
         }
         else 
         i++;
     }
     if(j==s.size()){
         pos=i-s.size();
         break;
     }
 }
 cout<<pos<<" ";
 
 
 
return 0 ;
 }
 
/* In this algorithm 
1. first we made prefix table in that we are check that the starting elelemnts are maching which end one or not.
2. then we can match the pattern with the given string
3. in that on prefix table string we place j and i on main string in this i only move forward direction but j can backtact , j will backtrack when there the mismatch happen and we checj i with j+1 element .
*/