#include <bits/stdc++.h>

using namespace std;

#define ll long long int
/*
1. XOR of all a[i] --> x; --> o(n)
2. x ^ (1^2^3^4......^n) --> o(n)
3. [x^y] = num -> o(1)
4. Seperate i^2 baskets. -> o(n)
5. Seperate (1....N) in 2 baskets.
6. XOr of both baskets to find missing and repeating number.
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{

    // Write your code here
    pair<int, int> a;
    unordered_map<int, bool> mp;

    for (auto i : arr)
    {
        if (mp.find(i) == mp.end())
        {
            mp[i] = true;
        }
        else
        {
            a.second = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
        {
            a.first = i;
        }
    }

    return a;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    pair<int, int> ans = missingAndRepeating(a, n);

    cout << ans.first << " " << ans.second;

    return 0;
}