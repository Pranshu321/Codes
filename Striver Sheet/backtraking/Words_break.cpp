#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void words(string s, int idx, vector<string> &dic, vector<string> &ans, string &curr)
{
    if (idx >= s.size())
    {
        ans.push_back(curr);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        string breakword = s.substr(idx, i - idx + 1); // taking a word from string

        bool isPresent = false;
        for (auto j : dic) // Checking in dictionary that it is present or not
        {
            if (j.compare(breakword) == 0) // if present
            {
                isPresent = true; // ispresent true;
                break;
            }
        }

        if (isPresent)
        {
            string store = curr; // Storing the value of curr for backtracking the prev positiron.

            curr += breakword + " "; // Taking the string as it is valid

            words(s, i + 1, dic, ans, curr); // Next call

            curr = store; // Backtracking
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    string curr;

    words(s, 0, dictionary, ans, curr);
    return ans;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<string> dictionary;
    int n;
    cin >> n;
    string s;

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        dictionary.push_back(a);
    }
    cin >> s;

    vector<string> print = wordBreak(s, dictionary);

    for (auto i : print)
    {
        cout << i << "\n";
    }

    return 0;
}