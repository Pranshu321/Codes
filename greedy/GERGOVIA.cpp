#include <bits/stdc++.h>

using namespace std;
/*Gergovia consists of one street, and every inhabitant of the city is a wine salesman. Everyone buys wine from other inhabitants of the city. Every day each inhabitant decides how much wine he wants to buy or sell. Interestingly, demand and supply is always the same, so that each inhabitant gets what he wants.

There is one problem, however: Transporting wine from one house to another results in work. Since all wines are equally good, the inhabitants of Gergovia don't care which persons they are doing trade with, they are only interested in selling or buying a specific amount of wine.

In this problem you are asked to reconstruct the trading during one day in Gergovia. For simplicity we will assume that the houses are built along a straight line with equal distance between adjacent houses. Transporting one bottle of wine from one house to an adjacent house results in one unit of work.

--> Simply hum ismai appne sabse pass wale se vine bottles karedhage ga , jo bhi sabse phela seller milega.
*/
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
    while (true)
    {
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<pair<int, int>> buy;
        vector<pair<int, int>> sell;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
                buy.push_back({a[i], i});
            else
                sell.push_back({a[i], i});
        }
        int ans = 0;
        int i = 0, j = 0;
        while (i < buy.size() and j < sell.size())
        {
            int x = min(buy[i].first, -sell[j].first);
            buy[i].first -= x;
            sell[j].first += x;
            int diff = abs(buy[i].second - sell[j].second);
            ans += (x * diff);
            if (buy[i].first == 0)
                i++;
            if (sell[j].first == 0)
                j++;
        }
        cout << ans << endl;
        cin >> n;
        if (n == 0)
            break;
    }

    return 0;
}