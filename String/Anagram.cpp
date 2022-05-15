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
    string a;
    cin >> a;
    string b;
    cin >> b;
    int hash[26] = {0};
    for (int i = 0; i < a.length(); i++)
    {
        hash[a[i] - 'a']++;
    }

    for (int i = 0; i < b.length(); i++)
    {
        hash[b[i] - 'a']--;
        if (hash[b[i] - 'a'] < 0)
        {
            cout << "Not Anagram";
            return 0;
        }
    }

    cout << "Anagram";

    return 0;
}