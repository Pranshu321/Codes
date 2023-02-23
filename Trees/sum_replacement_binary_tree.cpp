#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void sumtree(node *root)
{
    if (root == NULL)
        return;
    sumtree(root->left);
    sumtree(root->right);
    if (root->left != NULL)
        root->data += root->left->data;
    if (root->right != NULL)
        root->data += root->right->data;
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preorder(root);
    cout << endl;
    sumtree(root);
    preorder(root);
    return 0;
}
