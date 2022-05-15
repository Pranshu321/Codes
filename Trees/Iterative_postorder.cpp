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
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> s;
    stack<int> print;
    s.push(root);

    while (!s.empty())
    {
        node *curr = s.top();
        s.pop();
        print.push(curr->data);
        if (curr->left)
        {
            s.push(curr->left);
        }
        if (curr->right)
        {
            s.push(curr->right);
        }
    }
    while (!print.empty())
    {
        cout << print.top() << " ";
        print.pop();
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

    postorder(root);

    return 0;
}