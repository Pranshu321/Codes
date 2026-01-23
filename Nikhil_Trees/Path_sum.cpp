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

bool path_sum(Node *&root, int sum)
{
    if (!root)
        return false;

    if (!root->left and !root->right)
    {
        return sum == root->data;
    }

    bool l = path_sum(root->left, sum - root->data);
    bool r = path_sum(root->right, sum - root->data);

    return (l or r);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node *root = nullptr;

    // Build tree from image: target = 22
    insert(root, 5);                     // Root
    auto node4 = insert(root, 4, true);  // Left child of 5
    auto node8 = insert(root, 8, false); // Right child of 5

    auto node11 = insert(node4, 11, true); // Left child of 4
    insert(node11, 7, true);               // Left child of 11
    insert(node11, 2, false);              // Right child of 11

    insert(node8, 13, true);                    // Left child of 8
    auto node4_right = insert(node8, 4, false); // Right child of 8
    insert(node4_right, 1, false);              // Right child of 4

    // print(root);
    cout << path_sum(root, 23);

    return 0;
}