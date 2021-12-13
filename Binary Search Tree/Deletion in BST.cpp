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
node*inordersucc(node*root){
    node*curr=root;
    while(curr&&curr->left!=NULL)
    {curr=curr->left;
}
return curr;
}
node*deletion(node*root,int key){
    if(root==NULL)
    return NULL;
    if(key<root->data)
    root->left=deletion(root->left,key);
    else if(key>root->data)
    root->right=deletion(root->right,key);
    else{
        if(root->left==NULL){     // in this we handel both case 1 and case 2 if left is null then right child made node and root got deleted 
            node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL) // in this we handel both case 1 and case 2 if right is null then left child made node and root got deleted
        {node*temp=root->left;
        free(root);
        return temp;}
        node*temp=inordersucc(root->right); // inorder se inorder successor manwa rahe hai;
        root->data=temp->data;  // ab data change kar rahe hai
        root->right=deletion(root->right,temp->data); // now deleted the node which we want to delete
        
    }
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
	node*root=new node(4);
	root->left=new node(2);
	root->right=new node(5);
	root->left->left=new node(1);
	root->left->right=new node(3);
	root->right->right=new node(6);
	inorder(root); cout<<endl;
	node*ans=deletion(root,5);
	inorder(root);
	return 0;
}
