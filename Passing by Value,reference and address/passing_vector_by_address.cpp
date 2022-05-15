#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 void Passing_by_Address(vector<int> *b){ // This is working like double pointer , memory ke memory mai save ho raha hai.
     b->push_back(10);
     b->push_back(20);
     b->push_back(30);
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 vector<int>a;
 Passing_by_Address(&a);
 cout<<a[0]<<" "<<a[1]<<" "<<a[2];
 
 
 
return 0 ;
 
 
 } 