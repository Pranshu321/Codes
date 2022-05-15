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
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end()); // Sorting the ranges according to the starting ranges.
        int idx = 0;
        for (int i = 1; i < v.size(); i++) // merging the ranges
        {
            if (v[idx].second >= v[i].first)
            {
                v[idx].second = max(v[i].second, v[i].second); // Checking that the second part of first range and for second thing we check first or starting range if first range is less than second first part of second then we merge. eg:- (a,b) (c,d) :::: b<c then merge.
            }
            else
            {
                idx++;
                v[idx] = v[i];
            }
        }
        while (q--)
        {
            int k;
            cin >> k;
            int ans = -1;
            for (int i = 0; i <= idx; i++)
            {
                if (v[i].second - v[i].first + 1 >= k) // this when diffrence is greater than the k means the idx smallest we want we take asnwer as ans.
                {
                    ans = v[i].first + k - 1;
                    break;
                }
                else
                {
                    k = k - (v[i].second - v[i].first + 1);
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}