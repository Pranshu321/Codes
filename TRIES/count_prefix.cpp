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
    node *next[26];
    bool end;
    int wc;
    int end_with;
};

node *getNode()
{
    node *t = new node;
    t->end = false;

    for (int i = 0; i < 26; i++)
    {
        t->next[i] = NULL;
    }
    t->wc = 0;
    t->end_with = 0;
    return t;
}

void insert(node *root, string s)
{
    node *it = root;

    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!it->next[index])
        {
            it->next[index] = getNode();
        }
        it->next[index]->wc += 1;
        it = it->next[index];
    }
    it->end_with += 1;
    it->end = true;
}

bool search(node *root, string s)
{
    node *it = root;

    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!it->next[index])
        {
            return false;
        }
        it = it->next[index];
    }
    return it->end;
}

int countPerfix(node *root, string s)
{
    node *it = root;

    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!it->next[index] || it->next[index]->wc == 0)
        {
            return 0;
        }
        it = it->next[index];
    }
    return it->wc;
}

int countWordsEqualTo(node *root, string word)
{
    // Write your code here.
    node *it = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (!it->next[word[i] - 'a'] || it->next[word[i] - 'a']->end_with == 0)
        {
            return 0;
        }
        it = it->next[word[i] - 'a'];
    }
    return it->end_with;
}

void Del(node *root, string s)
{
    node *it = root;

    if (search(root, s))
    {
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            it->next[index]->wc -= 1;
            it = it->next[index];
        }
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    node *root = getNode();

    string s[] = {"pranshu", "app", "apple", "jain", "kale"};

    for (auto i : s)
    {
        insert(root, i);
    }

    cout << countPerfix(root, "ap");
    Del(root, "apple");
    cout << endl
         << countPerfix(root, "ap");
    cout << endl
         << countWordsEqualTo(root, "le");

    return 0;
}