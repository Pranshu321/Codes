#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pq.push(a[i]);
    }
    cout << pq.top() << "\n";
    // int ans = 0;
    while (pq.size() > 1)
    {
        int ans = 0;
        int x1 = pq.top();
        pq.pop();
        int x2 = pq.top();
        pq.pop();
        ans += x1 + x2;
        pq.push(ans);
    }

    cout << pq.top();

    return 0;
}