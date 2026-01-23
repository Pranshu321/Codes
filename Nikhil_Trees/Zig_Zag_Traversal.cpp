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

void zig_zag(Node *&root)
{
    bool left = false;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto x = q.front();
            q.pop();
            cout << x->data << " ";
            if (left)
            {
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
            else
            {
                if (x->right)
                    q.push(x->right);
                if (x->left)
                    q.push(x->left);
            }
            left = !left;
        }
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node *root = nullptr;
    insert(root, 5);                      // root = 5
    Node *left = insert(root, 3, true);   // left child = 3
    Node *right = insert(root, 8, false); // right child = 8
    insert(left, 2, true);                // left->left = 2
    insert(left, 4, false);               // left->right = 4
    insert(right, 6, true);               // right->left = 6
    insert(right, 9, false);              // right->right = 9

    zig_zag(root);

    return 0;
}