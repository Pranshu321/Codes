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
int maxPathuntil(node *root, int &ans)
{
    if (root == NULL)
        return -1;
    int left = maxPathuntil(root->left, ans);
    int right = maxPathuntil(root->right, ans);
    int nodemax = max(max(root->data, root->data + left + right), // in this the root->data+left+right is not the single path it is double path means we have calculate singlr path only.
                      max((root->data + left), (root->data + right)));
    ans = max(ans, nodemax);
    int singlepath = max(root->data, max((root->data + left), (root->data + right)));
    return singlepath;
}
int get_max(node *root)
{
    int ans = INT_MIN;
    maxPathuntil(root, ans);
    return ans;
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
    root->right->right = new node(5);
    cout << get_max(root);
    return 0;
}
