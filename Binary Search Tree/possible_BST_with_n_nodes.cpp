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
vector<node*>Construct_BST(int start,int end){
    vector<node*>trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<node*>leftsub=Construct_BST(start,i-1); //this is contructing the left sub tree 
        vector<node*>rightsub=Construct_BST(i+1,end);
        // constructing the right subtree
        for(int j=0;j<leftsub.size();j++){ // storing the subtree to left named  node to join to left side of tree futher
            node*left=leftsub[j];
            for(int k=0;k<rightsub.size();k++){
                node*right=rightsub[k]; // storing the subtree to right named  node to join to right side of tree futher
                node*Node=new node(i);
                Node->left=left; // making a left side of tree;
                Node->right=right; // making a right side of tree;
                trees.push_back(Node);
                
            }
        }
    }
    return trees;
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
	vector<node*>totaltrees=Construct_BST(1,3);
	for(int i=0;i<totaltrees.size();i++){
	    cout<<i+1<<" : ";
	    preorder(totaltrees[i]);
	    cout<<"\n";
	}
	return 0;
}
