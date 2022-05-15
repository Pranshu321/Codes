#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct comp
{
    bool operator()(Node *left, Node *right)

    {
        return (left->data > right->data);
    }
};

void preOrder(Node *root, string s, vector<string> &ans)
{
    if (!root)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        ans.push_back(s);
    }

    preOrder(root->left, s + "0", ans);
    preOrder(root->right, s + "1", ans);
}

vector<string> Huffman_Coding(string S, vector<int> f, int n)
{
    priority_queue<Node *, vector<Node *>, comp> pq;

    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node(f[i]);
        pq.push(temp);
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node(left->data + right->data);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node *root = pq.top();
    pq.pop();
    vector<string> ans;
    preOrder(root, "", ans);
    return ans;
}


int32_t main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        vector<string> ans = Huffman_Coding(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}