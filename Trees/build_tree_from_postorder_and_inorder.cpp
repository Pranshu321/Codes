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
int search(int inorder[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val)
        return i;
    }
    return -1;
}
node*buildtree(int inorder[],int postorder[],int start,int end){
    static int idx=4;
    if(start>end)
    return NULL;
    int val=postorder[idx];
    idx--;
    node*curr= new node(val);
    if(start==end)
    return curr;
    int pos=search(inorder,start,end,val);
   curr->right= buildtree(inorder,postorder,pos+1,end);
    curr->left=buildtree(inorder,postorder,start,pos-1);
    return curr;
    
}
void display(struct node*root){
    if(root==NULL)
    return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}


int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int inorder[]={4,2,1,5,3};
	int postorder[]={4,2,5,3,1};
	node*head=buildtree(inorder,postorder,0,4);
	display(head);
	return 0;
}
