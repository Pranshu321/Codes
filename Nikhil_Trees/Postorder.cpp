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

void postorder_recur(Node *root)
{
    if (!root)
        return;
    postorder_recur(root->left);
    postorder_recur(root->right);
    cout << root->data << " ";
}

void postorder_itr(Node *root)
{
    stack<Node *> s;
    while (true)
    {
        while (root)
        {
            if (root->right)
                s.push(root->right);
            s.push(root);
            root = root->left;
        }
        if (s.empty())
            return;
        root = s.top();
        s.pop();
        if (root->right && !s.empty() && s.top() == root->right)
        {
            s.pop();
            s.push(root);
            root = root->right;
        }
        else
        {
            cout << root->data << " ";
            root = nullptr;
        }
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

    postorder_itr(root);
    cout << "\n";
    postorder_recur(root);

    return 0;
}