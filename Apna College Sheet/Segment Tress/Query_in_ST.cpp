#include <bits/stdc++.h>

using namespace std;

#define int long long
const int M = 1e5 + 2;
int a[M], tree[M * 4];

int query(int node, int st, int end, int l, int r)
{
    if (st > r || end < l)
        return 0;
    if (st >= l && end <= r)
    {
        // cout << tree[node] << " ";
        return tree[node];
    }
    int mid = (st + end) / 2;
    int q1 = query(node * 2, st, mid, l, r);
    int q2 = query(node * 2 + 1, mid + 1, end, l, r);
    return q1 + q2;
}

void build(int node, int st, int end)
{
    if (st == end)
    {
        tree[node] = a[st];
        return;
    }

    int mid = (st + end) / 2;
    build(node * 2, st, mid);
    build(node * 2 + 1, mid + 1, end);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(1, 0, n - 1);
    while (1)
    {
        int q;
        cin >> q;
        if (q == -1)
        {
            break;
        }
        if (q == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}