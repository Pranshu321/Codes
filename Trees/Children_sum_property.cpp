#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void changeTree(node *root)
{
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    if (child < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left || root->right)
        root->data = tot;
}

void display(node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

int main()
{

    struct node *root = new node(2);
    root->left = new node(35);
    root->left->left = new node(2);
    root->left->right = new node(3);
    root->right = new node(10);
    root->right->left = new node(5);
    root->right->right = new node(2);
    display(root);
    changeTree(root);
    cout<<endl;
    display(root);

    return 0;
}
