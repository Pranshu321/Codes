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
node*BSTfrom_sorted_array(int a[],int start,int end){
    if(start>end)
    return NULL;
    int mid=(start+end)/2;
    node*root=new node(a[mid]);
    root->left=BSTfrom_sorted_array(a,start,mid-1);
    root->right=BSTfrom_sorted_array(a,mid+1,end);
    return root;
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
	int a[]={10,20,30,40,50};
	node*root=BSTfrom_sorted_array(a,0,4);
	preorder(root);
	return 0;
}
