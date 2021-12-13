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
    right=NULL;}
};
void preorder(struct node*root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node*root)
{ if(root==NULL)
return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
    
}
void postorder(struct node*root){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	struct node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	cout<<"Preorder : "; preorder(root); 
    cout<<"\n";
	cout<<"Inorder : ";inorder(root); cout<<"\n";
	cout<<"Postorder : ";postorder(root); cout<<"\n";
	return 0;
}
