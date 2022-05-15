#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 struct node{
     int data;
     node*left,*right;
     node(int val){
         data=val;
         left=right=NULL;
     }
 };

 vector<node*> treetotal(int start,int end){
     vector<node*>ans;
     if(start>end){
         ans.push_back(NULL);
         return ans;
     }

     for(int i=start;i<=end;i++){
         vector<node*>leftsub=treetotal(start,i-1);
         vector<node*>rightsub=treetotal(i+1,end);

         for(int j=0;j<leftsub.size();j++){
             node*lefti=leftsub[j];

             for(int k=0;k<rightsub.size();k++){
                 node*righty=rightsub[k];
                 node*Node=new node(i);
                 Node->left=lefti;
                 Node->right=righty;
                 ans.push_back(Node);
             }
         }
     }
     return ans;
 }

 void prerder(node*root){
     if(root==NULL)
     return;
     cout<<root->data<<" ";
     prerder(root->left);
     prerder(root->right);
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 vector<node*>Trees=treetotal(1,3);
 for(int i=0;i<Trees.size();i++){
	    cout<<i+1<<" : ";
	    prerder(Trees[i]);
	    cout<<"\n";
	}
 
 
 
 
return 0 ;
 
 
 } 