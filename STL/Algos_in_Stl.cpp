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
 vector<int>v={7,1,2,3,3,3,3,5};
 
 int mini=*(min_element(v.begin(),v.end()));
 cout<<"Minimum Element : "<<mini<<"\n";
 
 int mani=*(max_element(v.begin(),v.end()));
 cout<<"Maximum Element : "<<mani<<"\n";

 int con=(count(v.begin(),v.end(),3));
 cout<<"count Element : "<<con<<"\n";

 int sum=accumulate(v.begin(),v.end(),0);
 cout<<"SUm is : "<<sum<<"\n";

 int findi= *(find(v.begin(),v.end(),2));
 cout<<"Elmeent Finded : "<<findi<<"\n";
 



 
 
 
 
return 0 ;
 
 
 } 