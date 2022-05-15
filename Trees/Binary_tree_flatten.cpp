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
void flatten(node*root){
  if(root==NULL || (root->left==NULL && root->right==NULL))  {
  return;}
  if(root->left!=NULL){
  flatten(root->left);
      node*temp=root->right; // saving right node
      root->right=root->left; //right ki jagah left aa jayega
  root->left=NULL; // left mai NULL daal denge;
      
  
  node*t=root->right;
  while(t->right!=NULL){ // for finding the tail node;
      t=t->right;
  }
  t->right=temp; // and adding to temp node;
  }
  flatten(root->right);
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
	node*root=new node(4);
	root->left=new node(9);
	root->right=new node(5);
	root->left->left=new node(1);
	root->left->right=new node(3);
	root->right->right=new node(6);
	flatten(root);
	inorder(root);
	return 0;
}
