#include <bits/stdc++.h>

using namespace std;

#define int long long
const int M = 1e5 + 2;
int a[M], tree[M * 4];

void build(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = a[b];
        return;
    }

    int mid = (b + e) / 2;
    build(node * 2, b, mid);
    build(node * 2 + 1, mid + 1, e);
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
    for (int i = 1; i < 15; i++)
    {
        cout << tree[i] << " ";
    }

    return 0;
}