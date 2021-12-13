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
void rightmost(node*root){
    if(root==NULL)
    return;
    queue<node*>q;
    q.push(root); // in this we put first root node
    while(!q.empty()){
        int n=q.size(); // taking the size of the queue or the node present at that level
        for(int i=0;i<n;i++)
        { node*curr=q.front(); // saving front element
        q.pop();
            if(i==n-1) // checking if the element checking is answer or not
        cout<<curr->data<<" ";
        if(curr->left!=NULL)
        q.push(curr->left);
        if(curr->right!=NULL)
        q.push(curr->right);
            
        }
    }
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int height=0;
	node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	rightmost(root);
	return 0;
}
