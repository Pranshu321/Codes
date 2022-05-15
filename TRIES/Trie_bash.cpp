#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 const int int_size=32;
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
struct node{
 node*next[2];
};
node*getnode(){
    node*it=new node;
    for(int i=0;i<2;i++){
        it->next[i]=NULL;
    }
    return it;
}
node*Trie=getnode();
 void insert(int num){
     node*it=Trie;
     for(int i=int_size-1;i>=0;i--){
         int curr= (num>>1) & 1;
         if(!it->next[curr]){
            it->next[curr]=getnode();
         }
         else
         it=it->next[curr];
     }
 }

 int query(int num){
     node*it=Trie;
     int ans=0;
     for(int i=int_size-1;i>=0;i--){
         int curr=(num>>1) & 1;
         int oppo=curr xor 1;
         if(it->next[oppo]){
             it=it->next[oppo];
             ans |=1<<i;
         }
         else
         it=it->next[oppo xor 1];
     }
     return ans;
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n; cin>>n;
 vector<int>a(n);
 for(auto i:a){
     cin>>i;
 }
 Trie=new node();
 insert(0);
 vector<int> rmax(n+1,0);
 int R=0;
 for(int i=n-1;i>=0;i--){
     R=R xor a[i];
     if(i!=n-1){
         rmax[i]=max(rmax[i],query(R));
         insert(R);
     }
     else{
         rmax[i]=query(R);
         insert(R);
     }
 }
 free(Trie);
 Trie=new node();
 insert(0);
 int ans=0;
 int L=0;
 for(int i=0;i<n;i++){
     L=L xor a[i];
     ans=max(ans,query(L)+rmax[i+1]);
     insert(L);
 }
 cout<<ans<<"\n";
 
 
 
 
return 0 ;
 
 
 } 