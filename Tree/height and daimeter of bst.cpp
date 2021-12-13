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
int calcheight(node*root){
    if(root==NULL)
    return 0;
   int leftheight=calcheight(root->left);
    int rightheight=calcheight(root->right);
    return max(leftheight,rightheight)+1;
}
int calcdaimeter(node*root){
    if(root==NULL)
    return 0;
    int lheight=calcheight(root->left);
    int rhieght=calcheight(root->right);
    int currdaimeter= lheight+rhieght+1;
    
    int ldaimeter= calcdaimeter(root->left);
    int rdaimeter= calcdaimeter(root->right);
    return max(currdaimeter,max(ldaimeter,rdaimeter));
    
    
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	cout<<calcheight(root)<<"\n"<<calcdaimeter(root);
	
	
	return 0;
}
