#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
int height(node*root,int&res){
    if(root==NULL)
    return 0;
    int l=height(root->left,res);
    int r=height(root->right,res);
    
    res=max(res,1+l+r); // 1+l+r is for the diameter in which the left and right also the node by which left and right is included .   
    return 1 + max(l,r);
}
int diameter(node* root)
{
    if (root == NULL)
        return 0;
    int ans = INT_MIN; // This will store the final answer
    height(root, ans);
    return ans;
}
int main(){
   // int res=INT_MIN;
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    cout<<"Diameter is : "<<diameter(root);
    
    return 0;
}