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

bool sameTree(Node *&root1, Node *&root2)
{
    if (!root1 and !root2)
    {
        return true;
    }
    if (!root1 or !root2)
        return false;
    int cond = root1->data == root2->data;
    int cond2 = sameTree(root1->left, root2->left);
    int cond3 = sameTree(root1->right, root2->right);
    if (cond and cond2 and cond3)
    {
        return true;
    }
    return false;
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

    Node *root2 = nullptr;
    auto xi = insert(root2, 3);
    auto lei = insert(root2, 5, true);
    insert(lei, 5, true);

    cout << sameTree(root, root);

    return 0;
}