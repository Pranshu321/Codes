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
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back({a[i], i + 1});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int price = v[i].first;
        int stock = v[i].second;

        if (price * stock <= k)
        { // Price * Stock gives us the total no of value which should deducted from k value or we say total value.
            ans += stock;
            k -= (price * stock);
        }
        else
        {
            ans += (k / price); // When we cant take all stock then the limited no of stock which we can take.
            k -= price * (k / price);
        }
    }
    cout << "The maximum number of stock are : " << ans;

    return 0;
}