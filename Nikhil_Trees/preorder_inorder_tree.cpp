#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *&root, int val, bool l = true)
{
    if (!root)
    {
        root = new Node(val);
        return root;
    }
    if (l)
        return root->left = new Node(val);
    else
        return root->right = new Node(val);
}

void print(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

Node *buildTree(vector<int> &preorder, unordered_map<int, int> &mp, int rootIndex, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }
    Node *root = new Node(preorder[rootIndex]);
    int mid = mp[preorder[rootIndex]];
    if (mid > left)
    {
        root->left = buildTree(preorder, mp, rootIndex + 1, left, mid - 1);
    }
    if (mid < right)
    {

        root->right = buildTree(preorder, mp, rootIndex + mid - left + 1, mid + 1, right);
    }
    return root;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    auto root = buildTree(preorder, mp, 0, 0, inorder.size() - 1);
    print(root);

    return 0;
}