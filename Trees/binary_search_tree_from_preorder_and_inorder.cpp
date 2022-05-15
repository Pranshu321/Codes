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
int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(curr==inorder[i])
        return i;
    }
    return -1;
}
node*buildsubtree(int preorder[], int inorder[],int start,int end){
    static int idx=0;
    if(start>end)
    return NULL;
    int curr=preorder[idx];
    idx++;
    node*n=new node(curr);
    if(start==end)
    return n;
    int pos=search(inorder,start,end,curr);
    n->left=buildsubtree(preorder,inorder,start,pos-1);
    n->right=buildsubtree(preorder,inorder,pos+1,end);
    return n;
}
void inordero(struct node*root)
{ if(root==NULL)
return;
inordero(root->left);
cout<<root->data<<" ";
inordero(root->right);
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int preorder[]={1,2,4,3,5};
	int inorder[]={4,2,1,5,3};
	node*roty=buildsubtree(preorder,inorder,0,4);
	inordero(roty);
	return 0;
}
