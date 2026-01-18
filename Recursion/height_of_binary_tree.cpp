#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int height(Node*root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->left) , height(root->right))+1;
    // +1 is for the root node as it not counted
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node*root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(6);
    root->left->right = new Node(7);

    cout<<height(root);

    return 0;
}