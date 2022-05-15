#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
// Here we have to find the longest string which is present vy using all prefixes present in vector string eg:  n ni nin ninj ninja ninga is vector string
// ninja it is a word which have the longest prefix common that is ninj which can be traced already by other elements present in vector.

struct node
{
    node *next[26];
    bool end;
};

node *getnode()
{
    node *t = new node;

    for (int i = 0; i < 26; i++)
    {
        t->next[i] = NULL;
    }
    t->end = false;

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
            it->next[index] = getnode();
        }
        it = it->next[index];
    }
    it->end = true;
}

bool checkPrefixexists(node *root, string s)
{
    bool flag = true;

    node *it = root;

    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (it->next[index])
        {
            it = it->next[index];

            if (it->end == false)
                return false;
        }
        else
            return false;
    }

    return true;
}

string completeString(node *root, vector<string> &a)
{
    node *it = root;
    for (auto &i : a)
    {
        insert(it, i);
    }
    string longest = "";
    for (auto &i : a)
    {
        if (checkPrefixexists(root, i))
        {
            if (i.length() > longest.length())
            {
                longest = i;
            }
            else if (i.length() == longest.length() && i < longest) // i<longest check that string is lexographical smaller or not.
            {
                longest = i;
            }
        }
    }

    if (longest == "")
    {
        return "None";
    }
    return longest;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    node *root = getnode();
    vector<string> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    cout << completeString(root, v);

    return 0;
}