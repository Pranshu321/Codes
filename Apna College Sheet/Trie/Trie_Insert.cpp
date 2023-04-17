#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

struct Trie
{
    Trie *child[26];
    bool isEnd;
};

void insert(Trie *root, string s)
{
    Trie *curr = root;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        int idx = s[i] - 'a';
        if (curr->child[idx] == NULL)
        {
            curr->child[idx] = new Trie();
            curr = curr->child[idx];
        }
    }
    curr->isEnd = true;
}

bool search(Trie *root, string s)
{
    Trie *curr = root;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = s[i] - 'a';
        if (curr->child[idx] == NULL)
        {
            return false;
        }
        curr = curr->child[idx];
    }
    return true;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<string> s = {"Hello", "Bye", "Shu", "Hoon"};
    Trie *root = new Trie();
    for (auto i : s)
    {
        insert(root, i);
    }
    if (search(root, "Shu"))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}