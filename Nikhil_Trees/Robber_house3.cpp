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

vector<int> robber(Node *&root)
{
    if (!root)
    {
        return {0, 0};
    }
    auto left = robber(root->left);
    auto right = robber(root->right);
    // we decided to rob
    vector<int> op(2, 0);
    op[0] = root->data + left[1] + right[1];

    // we decided not to take
    op[1] = max(left[0], left[1]) + max(right[0], right[1]);
    return op;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node *root = nullptr;
    auto x = insert(root, 3);
    auto l = insert(root, 9, true);
    auto le = insert(root, 2, false);
    insert(le, 8, false);
    insert(le , 7 , true);
    insert(l , 3 , true);
    // print(root);
    auto ans = robber(root);
    cout << max(ans[0], ans[1]);

    return 0;
}