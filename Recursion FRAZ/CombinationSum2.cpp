#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(vector<int> &a, int idx, int sum, vector<int> &temp)
{
    if (sum == 0)
    {
        for (auto i : temp)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    if (idx >= a.size())
    {
        return;
    }
    if (a[idx] > sum)
    {
        return;
    }
    if (a[idx] <= sum)
    {
        temp.push_back(a[idx]);
        solve(a, idx, sum - a[idx], temp);
        temp.pop_back();
        while (idx + 1 < a.size() && a[idx] == a[idx + 1])
        {
            idx++;
        }
        solve(a, idx + 1, sum, temp);
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum;
    cin >> sum;
    vector<int> temp;
    sort(a.begin(), a.end());
    cout << "========================\n";
    solve(a, 0, sum, temp);
    return 0;
}