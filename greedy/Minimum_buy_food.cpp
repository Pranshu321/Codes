#include <bits/stdc++.h>

using namespace std;
// In this we have to find minimum number of day we have to buy the food.
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
    int s, n, m;
    cin >> s >> n >> m; // s :- number of days you have to survive.
    // n :- maximum you can buy food in a single day except sunday.
    // m :- unit of food required each day to survive.

    int x = s / 7;     // finding the week from we let know about sunday
    int y = s - x;     // subtrating sunday's
    int sm = s * m;    // total food required
    int days = sm / n; // days by simply dividing.
    if (sm % n != 0)   // if not perfect factor.
    {
        days++;
    }
    if (days <= y) // checking is total days which we can survive by food less than total days we have.
    {
        cout << "YES " << days << "\n";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}