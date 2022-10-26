// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Structure for a binary tree node
struct Node
{
    int data;
    Node *left, *right;
};

// A utility function to create a new node
struct Node *newNode(int key)
{
    struct Node *node = new Node;
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

// Utility function to store vertical order in map 'm'
// 'hd' is horizontal distance of current node from root.
// 'hd' is initially passed as 0
void helper(Node *root, int hd, map<int, vector<int>> &mp)
{
    if (root == NULL)
        return;
    mp[hd].push_back(root->data);
    helper(root->left, hd - 1, mp);
    helper(root->right, hd + 1, mp);
}
void verticalOrder(Node *root)
{
    // Your code here
    map<int, vector<int>> mp;
    vector<int> ans;
    helper(root, 0, mp);
    for (auto i : mp)
    {
        for (auto j : i.second)
            cout << j << " ";

        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is n :- ";
    verticalOrder(root);

    // for(auto i: ans){
    //     cout<<i<<" ";
    // }
    return 0;
}
