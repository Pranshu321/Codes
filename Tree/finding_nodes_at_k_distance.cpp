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
void Printsubnodes(node*root,int k){
  if(root==NULL || k<0)
  return;
  if(k==0){
  cout<<root->data<<" ";
  return; }
  Printsubnodes(root->left,k-1); // print sub nodes
  Printsubnodes(root->right,k-1);
}
 int printKnodes(node*root,node*target,int k){
     if(root==NULL) //for acenstors
     return -1;
     if(root==target){ // finding the targets
         Printsubnodes(root,k);
         return 0;
     }
     int dl=printKnodes(root->left,target,k);
     if(dl!=-1){ 
         if(dl+1==k)
         cout<<root->data<<" ";
         else
         Printsubnodes(root->right,k-dl-2);
         return dl+1;
     }
     int dr=printKnodes(root->right,target,k);
     if(dr!=-1){
         if(dr+1==k)
         cout<<root->data<<" ";
         else
         Printsubnodes(root->left,k-dr-2); // one distance coverd by the node to acentors.
         return dr+1;
     }
     return -1;
     
 }

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
//	root->left->right=new node(3);
//	root->right->right=new node(6);
printKnodes(root,root->left,1);
	return 0;
}
