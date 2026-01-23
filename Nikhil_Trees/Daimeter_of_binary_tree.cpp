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
int ans = 0;
int daimeter(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int lh = daimeter(root->left);
    int rh = daimeter(root->right);
    ans = max(ans, lh + rh);
    return max(lh + 1, rh + 1);
}

// Daimeter of the tree is defined as the maximum distance between the two nodes , and it is not true it always pass through the root.

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node *root = nullptr;
    auto x = insert(root, 3);
    auto le = insert(root, 5, true);
    insert(le, 5, true);
    insert(root, 8, false);

    print(root);
    cout<<"\nDiameter : "<<daimeter(root);

    return 0;
}