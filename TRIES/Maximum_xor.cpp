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
    node *next[2];
};

class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(int num)
    {
        node *it = root;

        for (int i = 31; i >= 0; i--) // Binary form of number
        {
            int bit = (num >> i) & 1;
            if (!it->next[bit])
            {
                it->next[bit] = new node();
            }
            it = it->next[bit];
        }
    }

    int FindMax(int num)
    {
        node *it = root;

        int maxixor = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (it->next[!bit]) // Checking that toggle bit present or not because to maximize xor there will be diffrent bit present in trie so this is the way.
            {
                maxixor = maxixor | (1 << i);
                it = it->next[!bit];
            }
            else
            {
                it = it->next[bit];
            }
        }
        return maxixor;
    }
};

int MaximumXOR(int n, int m, vector<int> &a, vector<int> &b)
{
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        trie.insert(a[i]);
    }
    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, trie.FindMax(b[i]));
    }
    return maxi;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<int> a;
    vector<int> b;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    cout << "The maximum XOR is : " << MaximumXOR(n, m, a, b);

    return 0;
}