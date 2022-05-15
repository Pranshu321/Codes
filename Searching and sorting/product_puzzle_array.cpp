#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
void product(vector<int> &a, int n)
{

    // code here
    vector<int> l(n), r(n);
    l[0] = 1;
    r[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        l[i] = l[i - 1] * a[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = r[i + 1] * a[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = l[i] * r[i];
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {  int a; cin>>a;
        v.push_back(a);
    }
    product(v, n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}