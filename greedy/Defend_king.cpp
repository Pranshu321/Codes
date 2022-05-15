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
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, n;
        cin >> x >> y >> n;
        vector<int> x_cor;
        vector<int> y_cor;
        x_cor.push_back(0);
        y_cor.push_back(0);
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            x_cor.push_back(u);
            y_cor.push_back(v);
        }
        x_cor.push_back(x + 1);
        y_cor.push_back(y + 1);
        sort(x_cor.begin(), x_cor.end());
        sort(y_cor.begin(), y_cor.end());

        int mx = INT_MIN, my = INT_MIN;
        for (int i = 0; i < x_cor.size() - 1; i++)
        {
            mx = max(mx, x_cor[i + 1] - x_cor[i] - 1);
            my = max(my, y_cor[i + 1] - y_cor[i] - 1);
        }
        cout << mx * my << "\n";
    }

    return 0;
}