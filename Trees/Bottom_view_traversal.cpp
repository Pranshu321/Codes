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

vector<int> bottomView(node *root)
{
    vector<int> ans;
    map<int, int> mp;
    if (!root)
    {
        return ans;
    }

    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        auto temp = it.first;
        auto line = it.second;
        mp[line] = temp->data;
        if (temp->left)
        {
            q.push({temp->left, line - 1});
        }

        if (temp->right)
        {
            q.push({temp->right, line + 1});
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(60);
    // root->right->right = new node(7);
    // root->right->left = new node(6);

    vector<int> ans = bottomView(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}