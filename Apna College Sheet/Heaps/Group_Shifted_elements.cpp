#include <bits/stdc++.h>

using namespace std;

#define int long long

string getdiff(string str)
{
    string shift = "";
    for (int i = 1; i < str.length(); i++)
    {
        int dif = str[i] - str[i - 1];
        if (dif < 0)
            dif += 26;

        shift += (dif + 'a');
    }

    return shift;
}

void solve(string str[], int n)
{
    map<string, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        string diff = getdiff(str[i]);
        mp[diff].push_back(i);
    }

    for (auto i : mp)
    {
        for (auto j : i.second)
        {
            cout << str[j] << " ";
        }
        cout << endl;
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string str[] = {"acd", "dfg", "wyz", "yab", "mop",
                    "bdfh", "a", "x", "moqs"};
    int n = sizeof(str) / sizeof(str[0]);
    solve(str, n);

    return 0;
}