#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void solve(vector<int> v)
{
    int i = 0, j = v.size()-1;
    int ans = 0;
    while (i <= j)
    {
        if (v[i] == v[j])
        {
            i++;
            j--;
        }
        if (v[i] < v[j])
        {
            i++;
            v[i] += v[i - 1];
            ans++;
        }
        if (v[i] > v[j])
        {
            j--;
            v[j] += v[j + 1];
            ans++;
        }
    }
    cout << "The anwer is " << ans << "\n";
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
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    solve(v);

    return 0;
}