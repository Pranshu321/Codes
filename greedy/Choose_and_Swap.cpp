#include <bits/stdc++.h>

using namespace std;

#define ll long long int
// In this we have string and we have to replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
string choose_and_swap(string a, int n)
{
    set<char> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        s.erase(a[i]);
        if (s.empty())
        {
            break;
        }
        auto x = *(s.begin());
        if (x < a[i])
        {
            auto y = a[i];
            for (int j = 0; j < n; j++)
            {
                if (a[j] == x)
                {
                    a[j] = y;
                }
                else if (a[j] == y)
                {
                    a[j] = x;
                }
            }
            break;
        }
    }
    return a;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    cout << "The lexicographically smallest string is : " << choose_and_swap(s, n);

    return 0;
}