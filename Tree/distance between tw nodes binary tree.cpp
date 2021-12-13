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
node*Lowest_commom_ancestor(node*root,int n1,int n2){
    if(root==NULL)
    return NULL;
    if(root->data==n1 || root->data==n2)
    return root;
    node*left=Lowest_commom_ancestor(root->left,n1,n2); //traversing left side for lowest coomon root
    node*right=Lowest_commom_ancestor(root->right,n1,n2); //same as above
    if(left!=NULL && right!=NULL)
    return root;
    if(left==NULL && right==NULL)
    return NULL;
    if(left!=NULL) 
    return Lowest_commom_ancestor(root->left,n1,n2);
    if(right!=NULL)
    return Lowest_commom_ancestor(root->right,n1,n2);
}
int find_dist(node*root,int k,int dist)
{ if(root==NULL)
return -1;
if(root->data==k) //checking the if it is required root or not
return dist;
int left=find_dist(root->left,k,dist+1); //left side distance from Lowest_commom_ancestor
if(left!=-1) //return left side distance 
return left;
int right=find_dist(root->right,k,dist+1);
if(right!=-1) //return right side distance
return right;
    
}
int dist_btw_nodes(node*root,int n1,int n2){
    node*lca=Lowest_commom_ancestor(root,n1,n2);
    int d1=find_dist(lca,n1,0);
    int d2=find_dist(lca,n2,0);
    return d1+d2;
    
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
	cout<<dist_btw_nodes(root,4,7);
	return 0;
}


