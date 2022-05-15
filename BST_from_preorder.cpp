#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct node{
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;}
    
};
node*Contruct_BST(int preorder[],int*preorder_inx,int key,int min,int max,int n){
if(*preorder_inx>=n)
return NULL;
node*root=NULL;
if(key>min && key<max){
    root=new node(key);
    *preorder_inx=*preorder_inx+1;
    if(*preorder_inx<n)
    root->left=Contruct_BST(preorder,preorder_inx,preorder[*preorder_inx],min,key,n);
if(*preorder_inx<n)
root->right=Contruct_BST(preorder,preorder_inx,preorder[*preorder_inx],key,max,n);
}
return root;
}
void preorderp(node*root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorderp(root->left);
    preorderp(root->right);
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int preorder[]={1,2,4,5,8,3,6,9,10,7};
	int n=10;
	int preorder_inx=0;
	node*root=Contruct_BST(preorder,&preorder_inx,preorder[0],INT_MIN,INT_MAX,n);
	preorderp(root);
	return 0;
}
