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

int minimum_Depth(Node *&root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 1;
    }
    if (!root->left)
    {
        return 1 + minimum_Depth(root->right);
    }
    if (!root->right)
    {
        return 1 + minimum_Depth(root->left);
    }
    return 1 + min(minimum_Depth(root->left), minimum_Depth(root->right));
}

Node *buildTree(vector<int> &nums, int start, int end)
{
    if (start > end)
        return NULL;
    int idx = start;
    for (int i = start + 1; i <= end; i++)
    {
        if (nums[i] > nums[idx])
        {
            idx = i;
        }
    }

    Node *root = new Node(nums[idx]);
    root->left = buildTree(nums, start, idx - 1);
    root->right = buildTree(nums, idx + 1, end);

    return root;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Node *root = buildTree(nums, 0, nums.size() - 1);
    print(root);

    return 0;
}