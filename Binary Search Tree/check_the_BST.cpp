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
      right=NULL;
  }
};
bool isBST(node*root,node*min=NULL,node*max=NULL){
    if(root==NULL)
    return true;
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool leftvalid=isBST(root->left,min,root);
    bool righttvalid=isBST(root->right,root,max);
    return leftvalid and righttvalid;
}   
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
node*root=new node(5);
	root->left=new node(2);
	root->right=new node(6);
// 	root->left->left=new node(4);
// 	root->left->right=new node(5);
// 	root->right->left=new node(6);
// 	root->right->right=new node(7);

// 	cout<<maxpathsum(root);
if(isBST(root,NULL,NULL))
cout<<"BALANCED";
else
cout<<"UNBALANCED";


	return 0;
}
