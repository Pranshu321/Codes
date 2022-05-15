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
node*Search(node*root,int key){
    if(root==NULL)
    return NULL;
    if(root->data==key)
    return root;
    if(key<root->data)
    return Search(root->left,key);
    else{
        return Search(root->right,key);
    }
    return root;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	node*root=new node(4);
	root->left=new node(2);
	root->right=new node(5);
	root->left->left=new node(1);
	root->left->right=new node(3);
	root->right->right=new node(6);
	if(Search(root,1)==NULL)
	cout<<"key doesnt exist";
	
	else cout<<"key exist";
	return 0;
}
