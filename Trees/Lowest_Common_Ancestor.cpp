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

node *lowest_common_ancestor(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    node *left = lowest_common_ancestor(root->left, n1, n2);
    node *right = lowest_common_ancestor(root->right, n1, n2);
    if (left != NULL && right != NULL)
        return root;
    if (left == NULL && right == NULL)
        return NULL;
    if (left != NULL)
        return lowest_common_ancestor(root->left, n1, n2);
    if (right != NULL)
        return lowest_common_ancestor(root->right, n1, n2);
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
    node *n = lowest_common_ancestor(root, 6, 4);
    cout << n->data;
    return 0;
}
