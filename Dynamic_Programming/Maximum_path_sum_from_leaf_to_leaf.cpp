#include<bits/stdc++.h>
using namespace std;
struct node
{ int data;
  node*left,*right;
  node(int val){
      data=val;
      left=right=NULL;
  }
    /* data */
};
int Maximum_path_sum_leaf_util(node*root,int&res){
    if(root==NULL)
    return 0;
    if(!root->left && !root->right){ // when root is the leaf node so its add its value
        return root->data;
    }
    int l=Maximum_path_sum_leaf_util(root->left,res);
    int r=Maximum_path_sum_leaf_util(root->right,res);
    if(root->left && root->right){ 
        res=max(res,l+r+root->data) ;  // checking for the child updatinfg the res

        return max(l,r)+root->data;  // and return the ans;
    }
    return (!root->left)?(r+root->data):(l+root->data); // if any one is NULL

}
int Maximum_path_sum_leaf(node*root){
    int res=INT_MIN;
   int val = Maximum_path_sum_leaf_util(root,res);
    
    if(res==INT_MIN){
        return val;
    }
    
    return res; // simply retuning the ans;
}

int main(){
    // int res=INT_MIN;
     node *root = new node(-15);
    root->left = new node(5);
    root->right = new node(6);
    root->left->left = new node(-8);
    root->left->right = new node(1);
    root->left->left->left = new node(2);
    root->left->left->right = new node(6);
    root->right->left = new node(3);
    root->right->right = new node(9);
    root->right->right->right= new node(0);
    root->right->right->right->left= new node(4);
    root->right->right->right->right= new node(-1);
    root->right->right->right->right->left= new node(10);
    cout<<"The maximum path sum from leaf to leaf is : "<<Maximum_path_sum_leaf(root);
    return 0;
}
