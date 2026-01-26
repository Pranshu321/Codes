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

Node *invertBinaryTree(Node *root)
{
    if (!root)
        return NULL;
    auto le = invertBinaryTree(root->left);
    auto ri = invertBinaryTree(root->right);

    root->left = ri;
    root->right = le;

    return root;
}

void print(Node *&root)
{
    if (!root)
        return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node *root = nullptr;
    // Constructing a full binary tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
        insert(root, 1);                      // root = 1
        // Arrays depicting preorder and inorder traversals of the above tree
        vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
        vector<int> inorder  = {4, 2, 5, 1, 6, 3, 7};
    Node *left = insert(root, 2, true);   // root->left = 2
    Node *right = insert(root, 3, false); // root->right = 3
    insert(left, 4, true);                // 2->left = 4
    insert(left, 5, false);               // 2->right = 5
    insert(right, 6, true);               // 3->left = 6
    insert(right, 7, false);              // 3->right = 7

    print(root);
    auto c = invertBinaryTree(root);
    cout << endl;
    print(c);

    return 0;
}