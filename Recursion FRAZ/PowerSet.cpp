#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> ans;
unordered_map<int, int> mp;

void oldsolve(vector<int> &a, int idx, vector<int> &temp)
{
    if (idx == a.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(a[idx]);
    oldsolve(a, idx + 1, temp);
    temp.pop_back();
    while (idx + 1 < a.size() and a[idx] == a[idx + 1])
    {
        idx++;
    }
    oldsolve(a, idx + 1, temp);
}

void solve(vector<int> &a, int idx, vector<int> &temp)
{
    if (idx == a.size())
    {
        ans.push_back(temp);
        return;
    }
    if (mp.find(a[idx]) == mp.end())
    {
        mp[a[idx]] = 1;
        temp.push_back(a[idx]);
        solve(a, idx + 1, temp);
        mp.erase(a[idx]);
        temp.pop_back();
        solve(a, idx + 1, temp);
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> temp;
    oldsolve(arr, 0, temp);
    cout << " ==================================== \n";
    for (auto i : ans)
    {
        if (i.size() == 0)
        {
            cout << "{}"
                 << "\n";
            continue;
        }
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}