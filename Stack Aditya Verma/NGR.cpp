#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
void NGR(int a[], int n)
{
    int res[n];
    if (n == 0)
    {

        return;
    }
    stack<int> s;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!s.empty() && a[s.top()] <= a[i])
        {
            s.pop();
        }
        res[i] = (s.empty()) ? -1 : a[s.top()];
        s.push(i);
    }
    for (auto i : res)
    {
        cout << i << " ";
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    NGR(a, n);

    return 0;
}