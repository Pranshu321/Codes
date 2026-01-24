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

string preorder(Node *root)
{
    if (!root)
    {
        return "null,";
    }
    string s = to_string(root->data) + ",";
    s += preorder(root->left);
    s += preorder(root->right);
    return s;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    // Create the bigger tree
    Node *bigRoot = nullptr;
    insert(bigRoot, 5);                         // root = 5
    Node *bigLeft = insert(bigRoot, 3, true);   // left child = 3
    Node *bigRight = insert(bigRoot, 8, false); // right child = 8
    insert(bigLeft, 2, true);                   // left->left = 2
    insert(bigLeft, 4, false);                  // left->right = 4
    insert(bigRight, 6, true);                  // right->left = 6
    insert(bigRight, 9, false);                 // right->right = 9

    // Create the smaller tree (subtree)
    Node *smallRoot = nullptr;
    insert(smallRoot, 3);                           // root = 3
    Node *smallLeft = insert(smallRoot, 2, true);   // left child = 2
    Node *smallRight = insert(smallRoot, 4, false); // right child = 4

    string b = preorder(bigRoot);
    string s = preorder(smallRoot);

    cout << b << "\n"
         << s;

    if (b.find(s) != string::npos)
    {
        cout << "Yes";
    }
    else
        cout << "No";

    return 0;
}