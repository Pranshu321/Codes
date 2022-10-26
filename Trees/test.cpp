#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 void display(priority_queue<int>pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 priority_queue<int>pq;
 pq.push(10);
 pq.push(8);
 pq.push(5);
 pq.push(1);
 display(pq);
 pq.emplace(2);
 cout<<"\n";
 display(pq);


 
 
 
return 0 ;
 
 
 } 