#include <bits/stdc++.h>

using namespace std;

#define ll long long int
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> s;
    node *temp = root;
    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    node *root = new node(8);
    root->left = new node(3);
    root->right = new node(5);
    root->left->left = new node(4);
    root->left->right = new node(9);
    root->right->left = new node(7);
    root->right->right = new node(2);

    preorder(root);

    return 0;
}