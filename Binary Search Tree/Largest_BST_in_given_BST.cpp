#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
}; // this will store all these parameter for each node
info largestBST(node*root){
    if(root==NULL)
    return{0,INT_MIN,INT_MAX,0,true};
    if(root->left==NULL && root->right==NULL)
    return {1,root->data,root->data,1,true}; // checking for leaf node
info leftinfo=largestBST(root->left); // for left tree
info rightinfo=largestBST(root->right); // for right tree
info curr;  // for current node
curr.size=(1+ leftinfo.size + rightinfo.size);  // updating the size of curr which is travelled through left and right tree 

if(leftinfo.isBST && rightinfo.isBST && leftinfo.max<root->data && rightinfo.min>root->data){
    curr.min=min(leftinfo.min,min(rightinfo.min,root->data)); // if it is bst updating min and max of curr; and ans is also the sameas size because it is max ans;
    curr.max=max(rightinfo.max,max(leftinfo.max,root->data));
    curr.ans=curr.size;
    curr.isBST=true;

    return curr;
}
    curr.ans=max(leftinfo.ans,rightinfo.ans);
    // curr.ans=curr.size;
    curr.isBST=false;
    return curr;

}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	node*root1=new node(5);
	root1->left=new node(6);
	root1->right=new node(3);
root1->left->left=new node(5);
// 	node*root2=new node(1);
// 	root2->left=new node(2);
// 	root2->right=new node(5);
cout<<"the largest BST is :- "<<largestBST(root1).ans;
	
	return 0;
}
