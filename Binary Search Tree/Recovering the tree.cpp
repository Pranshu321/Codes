#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
void swap(int *a,int *b){ // simple swapping
    int temp=*a;
    *a=*b;
    *b=temp;
}
void calcPointers(node*root,node**first,node**mid,node**last,node**prev){
    if(root==NULL)
    return;
    calcPointers(root->left,first,mid,last,prev); //left side tree
    if(*prev&& root->data<(*prev)->data){ // prev is not NULL and root data is less than prev data;
        if(!*first){  // for first time
            *first=*prev;  
            *mid=root;
        }
        else{   // for second time
            *last=root;
        }
    }
    *prev=root;
    calcPointers(root->right,first,mid,last,prev);
}
void restoreBST(node*root){
    node*first,*prev,*mid,*last;
    first=NULL;
    last=NULL;
    mid=NULL;
    prev=NULL;
    calcPointers(root,&first,&mid,&last,&prev);
    if(first&&last) // for case 1; discripency not to an adjaecent node
    swap(&(first->data),&(last->data));
    else if(first&&mid)  // for case 2: discripensy to adjacent node;
    swap(&(first->data),&(mid->data));
    
    
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
	node*root=new node(6);
	root->left=new node(9);
	root->right=new node(3);
	root->left->left=new node(1);
	root->left->right=new node(4);
	root->right->right=new node(13);
	inorder(root);
	restoreBST(root);
	cout<<endl;  inorder(root);
	return 0;
}