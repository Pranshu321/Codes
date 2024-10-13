#include <bits/stdc++.h>

using namespace std;

#define int long long
unordered_map<char, string> mp;

void solve(string &s, int idx, string &temp, vector<string> &ans)
{ // base
    if (idx >= s.size())
    {
        ans.push_back(temp);
        return;
    }
    // Task
    string key = mp[s[idx]];
    for (int j = 0; j < key.size(); j++)
    {
        temp.push_back(key[j]);
        solve(s, idx + 1, temp, ans);
        temp.pop_back();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    string s;
    cin >> s;
    vector<string> ans;
    string temp = "";
    solve(s, 0, temp, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}