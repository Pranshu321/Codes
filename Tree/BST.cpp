#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct node{
	  int data;
	  struct node*left;
	  struct node*right;
	  node(int val){
	      data=val;
	      left=NULL;
	      right=NULL;
	  }
	};
	node*BSTinsert(node*root,int val){
	    if(root==NULL)
	    return new node(val);
	    if(val<root->data)
	    root->left=BSTinsert(root->left,val);
	    else
	    root->right=BSTinsert(root->right,val);
	    
	    return root;
	}
	 void inorder(node*root){
	     if(root==NULL)
	     return;
	     inorder(root->left);
	     cout<<root->data<<" ";
	     inorder(root->right);
	 }
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	node*root=NULL;
	root=BSTinsert(root,5);
	BSTinsert(root,1);
	BSTinsert(root,3);
	BSTinsert(root,4);
	BSTinsert(root,2);
	BSTinsert(root,7);
	inorder(root);
	return 0;
}
