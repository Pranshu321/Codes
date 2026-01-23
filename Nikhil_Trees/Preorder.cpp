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

void preorder_recur(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder_recur(root->left);
    preorder_recur(root->right);
}

void preorder_itr(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
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
    insert(root, 8, false);

    preorder_itr(root);

    cout << "\n";
    preorder_recur(root);

    return 0;
}