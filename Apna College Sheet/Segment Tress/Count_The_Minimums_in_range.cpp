#include <bits/stdc++.h>

using namespace std;

#define int long long
const int M = 1e5 + 2;
int a[M];
pair<int, int> tree[M * 4];

pair<int, int> query(int node, int st, int end, int l, int r)
{
    if (st > r || end < l)
        return {INT_MAX, 0};
    if (st >= l && end <= r)
    {
        return tree[node];
    }
    int mid = (st + end) / 2;
    auto q1 = query(node * 2, st, mid, l, r);
    auto q2 = query(node * 2 + 1, mid + 1, end, l, r);
    pair<int, int> q;
    if (q1.first < q2.first)
        q = q1;
    else if (tree[node * 2].first > tree[node * 2 + 1].first)
        q = q2;
    else
    {
        q.first = q1.first;
        q.second = q1.second + q2.second;
    }
    return q;
}

void update(int node, int st, int end, int idx, int val)
{
    if (st == end)
    {
        tree[node].first = val;
        tree[node].second = 1;
        a[st] = val;
        return;
    }
    int mid = (st + end) / 2;
    if (idx <= mid)
        update(node * 2, st, mid, idx, val);
    else
        update(node * 2 + 1, mid + 1, end, idx, val);

    if (tree[node * 2].first < tree[node * 2 + 1].first)
        tree[node] = tree[node * 2];
    else if (tree[node * 2].first > tree[node * 2 + 1].first)
        tree[node] = tree[node * 2 + 1];
    else
    {
        tree[node].first = tree[node * 2].first;
        tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
    }
}

void build(int node, int st, int end)
{
    if (st == end)
    {
        tree[node].first = a[st];
        tree[node].second = 1;
        return;
    }

    int mid = (st + end) / 2;
    build(node * 2, st, mid);
    build(node * 2 + 1, mid + 1, end);

    if (tree[node * 2].first < tree[node * 2 + 1].first)
        tree[node] = tree[node * 2];
    else if (tree[node * 2].first > tree[node * 2 + 1].first)
        tree[node] = tree[node * 2 + 1];
    else
    {

        tree[node].first = tree[node * 2].first;
        tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            auto q = query(1, 0, n - 1, l, r - 1);
            cout << q.first << " " << q.second << endl;
        }
    }

    return 0;
}