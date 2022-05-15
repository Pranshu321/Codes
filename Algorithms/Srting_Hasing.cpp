#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 const int N=1e5+7,M=1e9+7;
 vector<long long>powers(N);
 int p=31;
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
long long calculatehash(string s){
    long long hash=0;
    for(int i=0;i<s.size();i++){
        hash+= ((s[i]-'a'+1)*powers[i]%M); // taking modulus M for lesser down the value. calculating the hasg function for each string same as the binary form.
    }
    return hash;
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);

 powers[0]=1;
 for(int i=1;i<N;i++){
     powers[i]=(powers[i-1]*p)%M;  // calculating power for eah character.
 }
 vector<string>strings={"aa" , "ab" ,"aa" , "b" , "cc" , "aa"};
 vector<long long>hashes;
 for(auto i:strings){
     hashes.push_back(calculatehash(i));
 }
 sort(hashes.begin(),hashes.end());
 int distinct=0;
 for(int i=0;i<hashes.size();i++){
     if(i==0 or hashes[i]!=hashes[i-1]){
         distinct++;
     }
 }
 cout<<distinct<<"\n";
 
 
 
 
return 0 ;
 
 
 } 