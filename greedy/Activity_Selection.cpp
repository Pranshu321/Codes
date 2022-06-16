#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

static bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int max_Meeting_can_be_Held(vector<pair<int, int>> v, int n)
{
    sort(v.begin(), v.end(), comp);
    int i = 0;
    int j = 1;
    int count = 1;
    while (j < n)
    {
        if (v[i].second < v[j].first)
        { // Checking the completion time and starting time of event.
            i = j;
            j++;
            count++;
        }
        else
        {
            j++;
        }
    }
    return count;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    cout << "The max meeting will be held are : " << max_Meeting_can_be_Held(v, n);

    return 0;
}