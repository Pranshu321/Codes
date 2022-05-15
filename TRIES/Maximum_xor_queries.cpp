#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *next[2];

    bool containsKey(int ind)
    {
        return (next[ind] != NULL);
    }
    Node *getnode(int ind)
    {
        return next[ind];
    }
    void putnode(int ind, Node *node)
    {
        next[ind] = node;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->putnode(bit, new Node());
            }
            node = node->getnode(bit);
        }
    }
    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->getnode(!bit);
            }
            else
            {
                node = node->getnode(bit);
            }
        }
        return maxNum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> ans(queries.size(), 0);
    vector<pair<int, pair<int, int>>> offlineQueries;
    sort(arr.begin(), arr.end());
    int index = 0;
    for (auto &it : queries)
    {
        offlineQueries.push_back({it[1], {it[0], index++}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    int i = 0;
    int n = arr.size();
    Trie trie;

    for (auto &it : offlineQueries)
    {
        while (i < n && arr[i] <= it.first)
        {
            trie.insert(arr[i]);
            i++;
        }
        if (i != 0)
            ans[it.second.second] = trie.findMax(it.second.first);
        else
            ans[it.second.second] = -1;
    }
    return ans;
}

int main()
{
    vector<int> a = {0, 1, 2, 3, 4};
    vector<vector<int>> que = {{1, 3}, {5, 6}};

    vector<int> ans = maxXorQueries(a, que);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}