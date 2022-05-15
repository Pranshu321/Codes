#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
void largestrectanglearea(vector<int>v){
  int i=0,ans=0,n=v.size();
    stack<int>st;
    v.push_back(0);
    while(i<n){
        while(!st.empty() && v[st.top()]>v[i]){ // this will check that stack top is longest or not and pop it till top became less than vector element or became empty;
            int t=st.top();
            int h=v[t];
            st.pop();
            if(st.empty()){ //if empty the i reperesent the base and top elemrnt hoight
                
            ans=max(ans,h*i);
            }
            else
            { int len=i-st.top()-1; //one back element is the required length;
                ans=max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    cout<<ans;
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n; cin>>n;
 vector<int>v;
 for(int i=0;i<n;i++){
     int a; cin>>a;
     v.push_back(a);
 }
 largestrectanglearea(v);

 
 
 
 
return 0 ;
 
 
 } 