#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 

vector<string> subset(string s){ // for generating the subsets.
    int n= (1<<s.size());
    vector<string> ans;
    for(int i=0;i<n;i++){
        string b;
        for(int bit=0;bit<s.size();bit++){
            if( i & (1<<bit))
            b.push_back(s[bit]);
        }
        if(b.size())   // excluding the emty string
        ans.push_back(b);
    }
    return ans;
}

bool isvowel(char ch){ // vowel checker
   return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int t; cin>>t;
 while(t--){
     int n;
     cin>>n;
     string str[n];
     for(int i=0;i<n;i++){
         cin>>str[i];
     }
     unordered_map<string,int> hsh; // hashing map
     for(int i=0;i<n;i++){
         set<char> distinct; // for entering the distinct vowels 
         for(char ch : str[i]){
             if(isvowel(ch)){ 
                 distinct.insert(ch); 
             }
         }
         string vowel_str; // converting set into string
         for(char ch : distinct){
             vowel_str.push_back(ch);
      
       }
       vector<string> all_subsets = subset(vowel_str); // storing all subsets.
       for( string vowel_sub : all_subsets){  // iterating to all subsets.
           hsh[vowel_sub]++;
       }
     }
     long long ans=0;
     for(auto &i : hsh){
         if(i.second<3) // we need only count with greater than 3
         continue;
         long long count = i.second;
         long long ways = count * (count-1) * (count-2) /6; // counting the ways
         if(i.first.size()%2==0) // if even then we have to minus otherwise addition.
         ans-=ways;
         else
         ans+=ways;
     }
     cout<<ans<<"\n";
 }
 
 
 
 
return 0 ;
 
 
 } 

/* 2
5
irena
arthos
tulu
3
alen
bira
cult

output : 1 0
*/