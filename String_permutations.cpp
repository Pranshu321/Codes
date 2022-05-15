#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 

 void permu(string s,int l , int h){
     if(l==h)
     cout<<s<<"\n";

     else{
         for(int i=l;i<=h;i++){
             swap(s[l],s[i]);
             permu(s,l+1,h);
             swap(s[l],s[i]);
         }
     }
}

 void permu_1(string s,int k){
     static int A[10]={0};
     static char res[10];
     if(s[k]=='\0'){
        res[k]='\0';
         cout<<res<<"\n";
     }
     else{
         for(int i=0;i<s.length();i++){
             if(A[i]==0){ // we have to check that element is available to add or not.
                 res[k]=s[i]; // we have to add it result string inorder to print as we can take it.
                 A[i]=1; // We have to mark it taken or visited .
                 permu_1(s,k+1); // Now we proceed to other char in string to add and check.
                 A[i]=0; // We have to back mark the element 0 as we have to use again again so we have backtract the vis array.
             }
         }
     }
 }

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 string s;
 cin>>s;
 int n=s.length();
 cout<<"This is the all permutations of String entered \n";
 cout<<"-----------------------------------\n";
 permu(s,0,n-1);
 cout<<"-----------------------------------\n";
 permu_1(s,0);
 
 
 
 
return 0 ;
 
 
 } 