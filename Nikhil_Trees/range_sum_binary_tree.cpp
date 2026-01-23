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

int rangeSum(Node *root, int low, int high)
{
    if (!root)
        return 0;
    int sum = 0;
    if (root->data > low)
    {
        sum += rangeSum(root->left, low, high);
    }
    if (root->data >= low and root->data <= high)
    {
        sum += root->data;
    }
    if (root->data < high)
    {
        sum += rangeSum(root->right, low, high);
    }
    return sum;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node *root = nullptr;
    auto x = insert(root, 10);
    auto le = insert(root, 5, true);
    insert(le, 7, false);
    insert(le, 3, true);
    insert(root, 15, false);

    print(root);

    cout << "\nAns : " << rangeSum(root, 6, 15);

    return 0;
}