#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *&root, int val, bool l = true)
{
    if (!root)
    {
        root = new Node(val);
        return root;
    }
    if (l)
        return root->left = new Node(val);
    else
        return root->right = new Node(val);
}

void print(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

vector<float> avgLevelorder(Node *root)
{
    if (!root)
        return {};
    queue<Node *> q;
    q.push(root);
    vector<float> ans;
    while (!q.empty())
    {
        int sum = 0;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto x = q.front();
            q.pop();
            sum += x->data;
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
        float res = sum / (float)n;
        ans.push_back(res);
    }
    return ans;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Node *root = nullptr;
    auto x = insert(root, 10);
    auto le = insert(root, 5, true);
    insert(le, 7, false);
    insert(le, 3, true);
    insert(root, 15, false);

    print(root);
    cout << endl;
    auto ans = avgLevelorder(root);
    for (auto o : ans)
    {
        cout << o << " ";
    }

    return 0;
}