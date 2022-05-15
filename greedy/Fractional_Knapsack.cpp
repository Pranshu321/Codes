#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int Fractional_Knapsack(vector<pair<int, int>> a, int n, int W)
{
    vector<pair<double, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        x = a[i].first;  // Value
        y = a[i].second; // Weight

        int z = (x * 1.0) / (y * 1.0);
        v.push_back({z, i});
    }
    sort(v.begin(), v.end(), greater<pair<double, int>>());
    int sum_weight = 0;
    double max_profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum_weight + a[v[i].second].second < W)
        {
            max_profit += a[v[i].second].first;
            sum_weight += a[v[i].second].second;
        }
        else
        {
            double x = (W - sum_weight) * 1.0;
            max_profit += (x * v[i].first);
            break;
        }
    }
    return max_profit;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, W;
    cin >> n >> W;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cout << "The max Profit Will be : " << Fractional_Knapsack(v, n, W);

    return 0;
}

/*3 50
60 10
100 20
120 30
The max Profit Will be : 240*/