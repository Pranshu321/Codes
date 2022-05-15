#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int Minimum_Platforms(vector<pair<int, int>> v, int n)
{
    sort(v.begin(), v.end());
    int no_of_Platform = 1; // One because we start from the 2nd train coming so we have to assume that one platform is already present there.
    int j = 0;
    int i = 1;
    while (i < n)
    {
        if (v[i].first <= v[j].second) // Checking the departure time of first train with arrival time of second train.
        {
            no_of_Platform++;
        }
        else
        {
            j++;
        }
        i++;
    }
    return no_of_Platform;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cout << "The minimum number of Platforms are : " << Minimum_Platforms(v, n);

    return 0;
}