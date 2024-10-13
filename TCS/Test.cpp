#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    string s;
    cin >> s;
    char ans = s[0];
    int idx = s.size();
    unordered_map<char, pair<int, int>> mp;
    for (int i = 0; i < s.size(); i++)
    {
        int x = mp[s[i]].second;
        mp[s[i]] = {i, x + 1};
    }

    for (auto i : mp)
    {
        if (i.second.second == 1 and i.second.first < ans)
        {
            ans = i.first;
            idx = i.second.first;
        }
    }
    cout << ans;

    return 0;
}