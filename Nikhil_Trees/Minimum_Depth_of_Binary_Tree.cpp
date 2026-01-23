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

int minimum_Depth(Node *&root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 1;
    }
    if (!root->left)
    {
        return 1 + minimum_Depth(root->right);
    }
    if (!root->right)
    {
        return 1 + minimum_Depth(root->left);
    }
    return 1 + min(minimum_Depth(root->left), minimum_Depth(root->right));
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node *root = nullptr;
    auto x = insert(root, 3);
    auto le = insert(root, 5, true);
    insert(le, 5, true);
    insert(le, 7, false);
    auto r = insert(root, 8, false);
    insert(r, 10, false);

    print(root);
    cout << endl;
    cout << minimum_Depth(root);

    return 0;
}