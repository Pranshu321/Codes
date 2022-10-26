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
bool isbalanced(node *root, int *height)
{
    if (root == NULL)
        return true;
    int lh = 0, rh = 0;
    if (isbalanced(root->left, &lh) == false)
    {
        return false;
    }
    if (isbalanced(root->right, &rh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int height = 0;
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    node *root2 = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    if (isbalanced(root, &height) == true)
        cout << "balanced tree";
    else
        cout << "unbalanced tree";
    return 0;
}
