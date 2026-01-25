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

bool issymemtric(Node *&root1, Node *&root2)
{
    if (!root1 and !root2)
    {
        return true;
    }
    if (!root1 or !root2)
    {
        return false;
    }
    int cond1 = root1->data == root2->data;
    int cond2 = issymemtric(root1->left, root2->right);
    int cond3 = issymemtric(root1->right, root2->left);
    return cond1 and cond2 and cond3;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node *root = nullptr;
    insert(root, 1);                      // root
    Node *left = insert(root, 2, true);   // left child
    Node *right = insert(root, 2, false); // right child
    insert(left, 3, true);                // left-left
    insert(left, 4, false);               // left-right
    insert(right, 4, true);               // right-left
    insert(right, 3, false);              // right-right

    print(root);
    cout << "\nThe Symmetric: " << issymemtric(root->left, root->right);

    return 0;
}