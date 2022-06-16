#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

bool ispallin(int start, int end, string s)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void find_pallindromes(int idx, string s, vector<vector<string>> &ans, vector<string> &pallins)
{
    if (idx == s.length())
    {
        ans.push_back(pallins);
        return;
    }

    for (int i = idx; i < s.length(); i++)
    {
        if (ispallin(idx, i, s))
        {
            pallins.push_back(s.substr(idx, i - idx + 1));
            find_pallindromes(i + 1, s, ans, pallins);
            pallins.pop_back();
        }
    }
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<string>> ans;
    vector<string> temp;
    find_pallindromes(0, s, ans, temp);
    cout << " [ ";
    for (auto i : ans)
    {
        cout << " [ ";
        for (auto j : i)
        {
            cout << j << ",";
        }
        cout << " ] ";
    }
    cout << " ] ";

    return 0;
}