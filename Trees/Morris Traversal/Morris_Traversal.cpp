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
};

vector<int> MorrisPreorder(node *root)
{
    vector<int> preorder;
    node *cur = root;

    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            node *prev = cur->left;
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}

vector<int> MorrisInorder(node *root)
{
    vector<int> inorder;
    node *cur = root;

    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            node *prev = cur->left;
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    vector<int> ans = MorrisInorder(root);
    vector<int> ansi = MorrisPreorder(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout<<endl;
    for (auto i : ansi)
    {
        cout << i << " ";
    }

    return 0;
}