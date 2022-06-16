#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

bool word_break(vector<string> dic, string s)
{
    if (dic.size() == 0) // If the dictionary is empty then simply false
    {
        return false;
    }
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;                       // Stating that first element is present
    for (int i = 1; i <= s.size(); i++) // looping in string to break
    {
        for (int j = i - 1; j >= 0; j--) // breaking points
        {
            if (dp[j]) // If the break point is there
            {
                string word = s.substr(j, i - j);             // Break the string
                auto it = find(dic.begin(), dic.end(), word); // Check the word in dictionary

                if (it != dic.end())
                {
                    dp[i] = true; // Then mark true and break;s
                    break;
                }
            }
        }
    }
    return dp[s.size()];
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        string si;
        cin >> si;
        v.push_back(si);
    }

    string s;
    cin >> s;

    if (word_break(v, s))
        cout << "Yes present";

    else
    {
        cout << "Not present";
    }

    return 0;
}