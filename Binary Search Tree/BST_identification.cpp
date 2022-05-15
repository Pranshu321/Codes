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
bool isIdeantical(node*root1,node*root2){
    if(root2==NULL && root1==NULL)
    return true;
    else if(root1==NULL || root2==NULL)
    return false;
    else{
        bool cond1=root1->data==root2->data;
        bool cond2=isIdeantical(root1->left,root2->left);
        bool cond3=isIdeantical(root1->right,root2->right);
        
        if(cond1 && cond3 && cond2)
        return true;
        else
        return false;
    }
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	node*root1=new node(1);
	root1->left=new node(2);
	root1->right=new node(3);
	node*root2=new node(1);
	root2->left=new node(2);
	root2->right=new node(3);
	if(isIdeantical(root1,root2))
	cout<<"BST's Are Identical";
	else
	cout<<"BST's Are Not Identical";
	return 0;
}
