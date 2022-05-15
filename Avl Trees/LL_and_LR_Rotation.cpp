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
    int height;
    node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
} *root = NULL;

int height_tree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height_tree(root->left), height_tree(root->right)) + 1;
}

node *LLrotation(node *p)
{
    node *pl = p->left;
    node *plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = height_tree(p);
    pl->height = height_tree(pl);

    if (root == p)
    {
        root = pl;
    }

    return pl;
}
node *LRrotation(node *p)
{
    node *pl = p->left;
    node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = height_tree(pl);
    p->height = height_tree(p);
    plr->height = height_tree(plr);

    if (root == p)
    {
        root = plr;
    }
    return plr;
}

int BalanceFactor(node *root)
{
    int hl, hr;
    hl = (root && root->left) ? root->left->height : 0;
    hr = (root && root->right) ? root->right->height : 0;

    return hl - hr;
}

node *Rinsert(node *root, int key)
{
    node *t = new node(key);
    if (root == NULL)
    {
        root = t;
        return t;
    }
    if (key < root->data)
    {
        root->left = Rinsert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = Rinsert(root->right, key);
    }
    root->height = height_tree(root);

    if (BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1)
    {
        return LLrotation(root);
    }
    if (BalanceFactor(root) == 2 && BalanceFactor(root->left) == -1)
    {
        return LRrotation(root);
    }

    return root;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    root = Rinsert(root, 20);
    Rinsert(root, 5);
    Rinsert(root, 3);
    preorder(root);

    return 0;
}