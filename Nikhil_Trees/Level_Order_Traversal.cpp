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

void levelorder(Node *root)
{
    if (!root)
        return;

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
            if (x->left)
            {
                q.push(x->left);
            }
            if (x->right)
            {
                q.push(x->right);
            }
        }
        cout << endl;
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

    levelorder(root);

    return 0;
}