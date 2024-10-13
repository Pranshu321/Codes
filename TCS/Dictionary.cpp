#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string p, s;
    cin >> p >> s;
    unordered_map<char, int> mp;
    for (int i = 0; i < p.size(); i++)
    {
        mp[p[i]] = i;
    }
    vector<pair<int, char>> v;
    for (auto i : s)
    {
        v.push_back({mp[i], i});
    }
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x.second;
    }

    return 0;
}