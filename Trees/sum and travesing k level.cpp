#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void level_traversing(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root); // the NULL shows the end of the level
    q.push(NULL); // first we push root element
    while (!q.empty())
    {
        node *n = q.front(); // then check front is NULL or any root and also
        // check it have child or not if yes push in the queue;
        // at end we push NULL if queue is not empty.
        q.pop();
        if (n != NULL)
        {
            cout << n->data << " ";
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}
int sum_at_k(node *root, int k)
{
    if (root == NULL)
        return 0;
    queue<node *> q;
    int level = 0, sum = 0;
    q.push(root); // the NULL shows the end of the level
    q.push(NULL); // first we push root element
    while (!q.empty())
    {
        node *n = q.front(); // then check front is NULL or any root and also
        // check it have child or not if yes push in the queue;
        // at end we push NULL if queue is not empty.
        q.pop();
        if (n != NULL)
        {
            if (level == k)
            {
                sum += n->data;
            }
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        else if (!q.empty())
        {
            level++;
            q.push(NULL);
        }
    }
    return sum;
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    level_traversing(root);
    cout << "\n"
         << sum_at_k(root, 2);

    return 0;
}
