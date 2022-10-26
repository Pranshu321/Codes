#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
    node(int x, node *left, node *right) : data(x), left(left), right(right) {}
};
map<int, vector<node *>> mp;
vector<node *> Construct_BST(int n)
{
    vector<node *> ans;
    if (n % 2 == 0)
    {
        return ans;
    }
    if (mp.count(n) > 0)
    {
        return mp[n];
    }
    mp[0] = {};
    mp[1] = {new node(0)};

    for (int i = 1; i < n; i += 2)
    {
        vector<node *> leftsubtree = Construct_BST(i);
        vector<node *> rightsubtree = Construct_BST(n - i - 1);

        for (auto j : leftsubtree)
        {
            for (auto k : rightsubtree)
            {
                node *root = new node(0, j, k);
                ans.push_back(root);
            }
        }
    }
    return mp[n] = ans;
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n; cin>>n;
    vector<node *> totaltrees = Construct_BST(n);
    for (int i = 0; i < totaltrees.size(); i++)
    {
        cout << i + 1 << " : ";
        preorder(totaltrees[i]);
        cout << "\n";
    }
    return 0;
}
