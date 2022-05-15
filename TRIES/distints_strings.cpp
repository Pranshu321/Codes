#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int cnt = 1;
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
void getdistinct(node *root, string s)
{
    node *it = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!it->next[index])
        {
            cnt++;
            it->next[index] = getnode();
        }
        it = it->next[index];
    }
    it->end = true;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    node *root = getnode();
    string s;
    cin >> s;
    int n = s.length();
    set<string> st;
    for (int i = 0; i < n; i++)
    {
        string str = "";
        for (int j = i; j < n; j++)
        {
            str = str + s[j];
            st.insert(str);
        }
    }

    for (auto i : st)
        getdistinct(root, i);

    cout << cnt;
    return 0;
}