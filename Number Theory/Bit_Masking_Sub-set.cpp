#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;

vector<vector<int>> sub_set(vector<int>&v,int n){
    int subset= (1<<n); // In this 1<<n is equal to 2^n terms.
    vector<vector<int>>subsets(n);
    for(int mask=0;mask<subset;mask++){
        vector<int>su;
        for(int i=0;i<n;i++){
            if((mask & (1<<i))!=0){
                su.push_back(v[i]);
            }
        }
        subsets.push_back(su);
    }
return subsets;
}

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n=3; 
 vector<int>v={2,4,5};
 auto subi=sub_set(v,n);
 for(auto i:subi){
     for(int ele:i){
         cout<<ele<<" ";
     }
     cout<<endl;
 }

 
 
 
return 0 ;
 
 
 } 