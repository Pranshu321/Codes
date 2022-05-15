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
void verticleOrder(node*root,int hori_dist,map<int,vector<int>>&mp){
    if(root==NULL)
    return;
    mp[hori_dist].push_back(root->data);
    verticleOrder(root->left,hori_dist-1,mp);
    verticleOrder(root->right,hori_dist+1,mp);
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	node*root=new node(10);
	root->left=new node(7);
	root->right=new node(4);
	root->left->left=new node(3);
	root->left->right=new node(11);
	root->right->left=new node(14);
	root->right->right=new node(6);
	map<int,vector<int>>mp;
	int hori_dist=0;
	verticleOrder(root,hori_dist,mp);
	map<int,vector<int>>:: iterator it;
	for(it=mp.begin();it!=mp.end();it++){
	    for(int i=0;i<(it->second).size();i++){
	        cout<<(it->second)[i]<<" ";
	    }
	    cout<<"\n";
	}
	
	return 0;
}