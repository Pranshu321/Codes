#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 2, MOD = 1e9 + 7;

struct grp
{
    int sum, pref, suff, ans;
};

grp tree[4 * N];
int a[N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        if (a[st] <= 0)
        {
            tree[node].sum = a[st];
            tree[node].pref = tree[node].suff = tree[node].ans = 0;
        }
        else
        {
            tree[node].sum = tree[node].pref = tree[node].suff = tree[node].ans = a[st];
        }
        return;
    }

    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    tree[node].pref = max(tree[2 * node].pref, tree[2 * node].sum + tree[2 * node + 1].pref);
    tree[node].suff = max(tree[2 * node + 1].suff, tree[2 * node + 1].sum + tree[2 * node].suff);
    tree[node].ans = max(tree[2 * node].suff + tree[2 * node + 1].pref, max(tree[2 * node].ans, tree[2 * node + 1].ans));
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val;
        if (a[st] <= 0)
        {
            tree[node].sum = a[st];
            tree[node].pref = tree[node].suff = tree[node].ans = 0;
        }
        else
        {
            tree[node].sum = tree[node].pref = tree[node].suff = tree[node].ans = a[st];
        }
        return;
    }

    int mid = (st + en) / 2;
    if (idx <= mid)
    {
        update(2 * node, st, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, en, idx, val);
    }
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    tree[node].pref = max(tree[2 * node].pref, tree[2 * node].sum + tree[2 * node + 1].pref);
    tree[node].suff = max(tree[2 * node + 1].suff, tree[2 * node + 1].sum + tree[2 * node].suff);
    tree[node].ans = max(tree[2 * node].suff + tree[2 * node + 1].pref, max(tree[2 * node].ans, tree[2 * node + 1].ans));
}

signed main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(1, 0, n - 1);
    cout << tree[1].ans << endl;

    while (m--)
    {
        int idx, val;
        cin >> idx >> val;
        update(1, 0, n - 1, idx, val);
        cout << tree[1].ans << endl;
    }
    return 0;
}
