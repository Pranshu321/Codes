#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void ZigZagTraversal(node*root){
    if(root==NULL)
    return;
    stack<node*>currLevel;
    stack<node*>nextLevel;
    currLevel.push(root);
    bool lefttoright=true;
    while(!currLevel.empty()){
        node*temp=currLevel.top();
        currLevel.pop();
        if(temp){
            cout<<temp->data<<" ";
            if(lefttoright){
                if(temp->left)
                nextLevel.push(temp->left);
                if(temp->right)
                nextLevel.push(temp->right);
            }
            else{
                if(temp->right)
                nextLevel.push(temp->right);
                if(temp->left)
                nextLevel.push(temp->left);
            }
        }
        if(currLevel.empty()){
            lefttoright=!lefttoright;
            swap(currLevel,nextLevel);
        }
    }
}
void preorder(node*root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	node*root=new node(12);
	root->left=new node(9);
	root->right=new node(15);
	root->left->left=new node(5);
	root->left->right=new node(10);
	ZigZagTraversal(root);
	return 0;
}
