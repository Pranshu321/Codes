#include <bits/stdc++.h>

using namespace std;

#define int long long

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> robbing_binary_tree(TreeNode *&root)
{
    if (!root)
    {
        return {0, 0};
    }
    auto left_choices = robbing_binary_tree(root->left);
    auto right_choices = robbing_binary_tree(root->right);
    vector<int> options(2, 0);
    // taking
    options[0] = root->val + left_choices[1] + right_choices[1];
    options[1] = max(left_choices[0], left_choices[1]) + max(right_choices[0], right_choices[1]);
    return options;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // Prepapre binary tree houses
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    auto result = robbing_binary_tree(root);
    cout << max(result[0], result[1]);

    return 0;
}