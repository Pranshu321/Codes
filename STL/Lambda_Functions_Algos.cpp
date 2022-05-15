#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 vector<int>a={2,4,-6};
 cout<< all_of(a.begin(),a.end(),[](int x){return x%2==0;})<<"\n";
 
 cout<< any_of(a.begin(),a.end(),[](int x){return x>0;})<<"\n";
 
 cout<< none_of(a.begin(),a.end(),[](int x){return x>0;})<<"\n";

 
 
 
 
return 0 ;
 
 
 } 