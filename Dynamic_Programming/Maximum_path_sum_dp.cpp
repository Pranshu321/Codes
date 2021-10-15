#include<bits/stdc++.h>
using namespace std;
struct node
{
    /* data */
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};

int max_path_sum(node*root,int&res){
   if(root==NULL)
   return 0;
   int l=max_path_sum(root->left,res);
   int r=max_path_sum(root->right,res);
   int temp=max(max(l,r)+root->data,root->data);
   int ans=max(temp,l+r+root->data);
   res=max(res,ans);

   return ans;
}
int main(){
    int res=INT_MIN;
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    cout<<"The maximum path sum is : "<<max_path_sum(root,res);
    return 0;
}