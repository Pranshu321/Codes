#include<bits/stdc++.h>
 using namespace std;
 #include <ext/pb_ds/assoc_container.hpp>
 #include<ext/pb_ds/tree_policy.hpp>
 using namespace __gnu_pbds;
 #define ll long long int
 template<class T> using op_set = tree<T,null_type,less<T>,
                         rb_tree_tag,tree_order_statistics_node_update>;
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int q; cin>>q;
 op_set<int>s;
 while(q--){
     int c; cin>>c;
     if(c==1){
         int t; cin>>t;
         s.insert(t);
     }
     else if(c==2){
       int t; cin>>t;
       cout<<*s.find_by_order(t)<<"\n"; // K-th element in a set (counting from zero ).
     }
     else{
      int t; cin>>t;
      cout<<s.order_of_key(t)<<"\n"; // Number of items strictly smaller than the element entered
     }
 }
 
 
 
 
return 0 ;
 
 
 } 